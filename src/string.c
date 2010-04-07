/* $Id$ */

#include <stdio.h>
#include "types.h"
#include "libemu.h"
#include "global.h"
#include "string.h"
#include "os/strings.h"
#include "file.h"

extern void f__23E1_01C2_0011_24E8();
extern void emu_File_ReadWholeFile();

/**
 * Decompress a string.
 *
 * @param source The compressed string.
 * @param dest The decompressed string.
 * @return The length of decompressed string.
 */
uint16 String_Decompress(char *source, char *dest)
{
	uint16 count;
	char *s;

	count = 0;

	for (s = source; *s != '\0'; s++) {
		uint8 c = *s;
		if ((c & 0x80) != 0) {
			c &= 0x78;
			c >>= 3;
			dest[count++] = g_global->stringDecompress[c];
			c <<= 3;
			c += (*s & 0x07);
			c = g_global->stringDecompress[c + 0x10];
		}
		dest[count++] = c;
	}
	dest[count] = '\0';
	return count;
}

/**
 * Appends ".(ENG|FRE|...)" to the given string.
 *
 * @param name The string to append extension to.
 * @return The new string.
 */
char *String_GenerateFilename(char *name)
{
	snprintf(g_global->stringFilename, sizeof(g_global->stringFilename), "%s.%s", name, g_global->string_31D8 + g_global->language * 4);
	return g_global->stringFilename;
}

/**
 * Returns a pointer to the string at given index in given buffer.
 *
 * @param buffer The content of a string file.
 * @param index The index of the string.
 * @return The pointer to the string.
 */
char *String_GetFromBuffer_ByIndex(char *buffer, uint16 index)
{
	return buffer + ((uint16 *)buffer)[index];
}

/**
 * Returns a pointer to the string at given index in current string file.
 *
 * @param index The index of the string.
 * @return The pointer to the string.
 */
char *String_Get_ByIndex(uint16 index)
{
	char *buffer;

	buffer = (char *)emu_get_memorycsip(g_global->strings);
	return String_GetFromBuffer_ByIndex(buffer, index);
}

/**
 * Translates 0x1B 0xXX occurences into extended ASCII values (0x7F + 0xXX).
 *
 * @param source The untranslated string.
 * @param dest The translated string.
 */
void String_TranslateSpecial(char *source, char *dest)
{
	if (source == NULL || dest == NULL) return;

	while (*source != '\0') {
		char c = *source++;
		if (c == 0x1B) {
			c = 0x7F + (*source++);
		}
		*dest++ = c;
	}
	*dest = '\0';
}

/**
 * Loads the given language file in the memory, which is used after that with String_GetXXX_ByIndex().
 *
 * @param name The name of the language file to load (without extension).
 */
void String_Load(char *name)
{
	char *filename;

	if (g_global->strings.csip != 0) {
		emu_push(g_global->strings.s.cs); emu_push(g_global->strings.s.ip);
		emu_push(emu_cs); emu_push(0x0026); emu_cs = 0x23E1; f__23E1_01C2_0011_24E8();
		emu_sp += 4;

		g_global->strings.csip = 0;
	}

	if (name == NULL) return;

	filename = String_GenerateFilename(name);

	emu_push(0);
	emu_push(0x353F); emu_push(0x8282); /* filename = g_global->stringFilename*/
	emu_push(emu_cs); emu_push(0x0053); emu_cs = 0x253D; emu_File_ReadWholeFile();
	emu_sp += 6;

	g_global->strings.s.cs = emu_dx;
	g_global->strings.s.ip = emu_ax;
}

/**
 * Loads the string at given index from file with given file to given buffer, and decompress it.
 *
 * @param filename The file to load the string from.
 * @param index The index of the string to load.
 * @param buffer Where to load the string.
 * @param buflen The length of the buffer.
 * @return The length of decompressed string
 */
uint16 String_LoadFile(char *filename, uint16 index, char *buffer, uint16 buflen)
{
	uint8 file;
	uint16 offset;
	uint16 len;
	char *s;

	if (filename == NULL || buffer == NULL || buflen == 0) return 0;

	file = File_Open(filename, 1);
	File_Seek(file, index * 2, 0);
	File_Read(file, &offset, 2);
	File_Seek(file, offset, 0);
	File_Read(file, buffer, buflen);
	File_Close(file);

	len = strlen(buffer) + 1;

	s = buffer + buflen - len;
	memmove(s, buffer, len);
	return String_Decompress(s, buffer);
}
