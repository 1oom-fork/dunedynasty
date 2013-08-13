/* net.c */

#include <assert.h>
#include <enet/enet.h>
#include <stdio.h>

#include "net.h"

#include "client.h"
#include "server.h"
#include "../house.h"
#include "../opendune.h"
#include "../pool/house.h"

#if 0
#define NET_LOG(FORMAT,...)	\
	do { fprintf(stderr, "%s:%d " FORMAT "\n", __FUNCTION__, __LINE__, __VA_ARGS__); } while (false)
#else
#define NET_LOG(...)
#endif

enum HouseFlag g_human_houses;
enum NetHostType g_host_type;
static ENetHost *s_host;
static ENetPeer *s_peer;

/*--------------------------------------------------------------*/

void
Net_Initialise(void)
{
	enet_initialize();
	atexit(enet_deinitialize);
}

static void
Server_Synchronise(void)
{
	int clients_connected = 0;

	g_human_houses = 0;

	while (clients_connected == 0) {
		ENetEvent event;
		if (enet_host_service(s_host, &event, 1000) == 0)
			continue;

		switch (event.type) {
			case ENET_EVENT_TYPE_RECEIVE:
				{
					bool success = false;
					ENetPacket *packet = event.packet;

					if (packet->dataLength == 2 && packet->data[0] == '=') {
						enum HouseType houseID = packet->data[1];
						if (HOUSE_HARKONNEN <= houseID && houseID < HOUSE_MAX
								&& !(g_human_houses & (1 << houseID))) {
							event.peer->data = (void *)houseID;

							g_human_houses |= (1 << houseID);
							House_Get_ByIndex(houseID)->flags.human = true;

							success = true;
						}
					}

					if (success) {
						clients_connected++;
						enet_peer_send(event.peer, 0, packet);
					}
					else {
						enet_packet_destroy(packet);
						enet_peer_disconnect(event.peer, 0);
					}
				}
				break;

			case ENET_EVENT_TYPE_DISCONNECT:
			case ENET_EVENT_TYPE_CONNECT:
			case ENET_EVENT_TYPE_NONE:
			default:
				break;
		}
	}

	enet_host_service(s_host, NULL, 0); /* XXX */
}

static void
Client_Synchronise(void)
{
	unsigned char buf[2];
	buf[0] = '=';
	buf[1] = g_playerHouseID;

	ENetPacket *packet
		= enet_packet_create(&buf, 2, ENET_PACKET_FLAG_RELIABLE);

	enet_peer_send(s_peer, 0, packet);

	enet_host_service(s_host, NULL, 0); /* XXX */
}

void
Net_Synchronise(void)
{
	switch (g_host_type) {
		case HOSTTYPE_DEDICATED_SERVER:
		case HOSTTYPE_CLIENT_SERVER:
			Server_Synchronise();
			break;

		case HOSTTYPE_DEDICATED_CLIENT:
			Client_Synchronise();
			break;

		default:
			return;
	}
}

bool
Net_CreateServer(int port)
{
	const int max_clients = HOUSE_MAX;

	if (g_host_type == HOSTTYPE_NONE && s_host == NULL && s_peer == NULL) {
		ENetAddress address;
		address.host = ENET_HOST_ANY;
		address.port = port;

		s_host = enet_host_create(&address, max_clients, 2, 0, 0);
		if (s_host != NULL) {
			ENetEvent event;

			NET_LOG("%s", "Created server.");

			if (enet_host_service(s_host, &event, 10000) > 0) {
				if (event.type == ENET_EVENT_TYPE_CONNECT) {
					NET_LOG("A new client connected from %x:%u.",
							event.peer->address.host, event.peer->address.port);

					g_host_type = HOSTTYPE_CLIENT_SERVER;
					return true;
				}
			}

			/* Timeout. */
			enet_host_destroy(s_host);
			s_host = NULL;
		}
	}

	return false;
}

bool
Net_ConnectToServer(const char *hostname, int port)
{
	if (g_host_type == HOSTTYPE_NONE && s_host == NULL && s_peer == NULL) {
		ENetAddress address;
		enet_address_set_host(&address, hostname);
		address.port = port;

		s_host = enet_host_create(NULL, 1, 2, 57600/8, 14400/8);
		if (s_host != NULL) {
			s_peer = enet_host_connect(s_host, &address, 2, 0);
			if (s_peer != NULL) {
				ENetEvent event;

				if (enet_host_service(s_host, &event, 5000) > 0
						&& event.type == ENET_EVENT_TYPE_CONNECT) {
					NET_LOG("Connected to server %s:%d\n", hostname, port);
					enet_host_service(s_host, &event, 0);

					g_host_type = HOSTTYPE_DEDICATED_CLIENT;
					return true;
				}

				/* Timeout. */
				enet_peer_reset(s_peer);
				s_peer = NULL;
			}

			/* Error creating peer. */
			enet_host_destroy(s_host);
			s_host = NULL;
		}
	}

	return false;
}