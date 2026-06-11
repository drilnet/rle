
//
// Украина (Ukraine). (C) Демидов С.В.
//

//#include <stdio.h>
#include <stdlib.h>

//
// VRLE8 Decoding.
//

	// Здесь загруженный файл.
	extern unsigned char *buffer;

	// Здесь массив для записи на диск.
	extern unsigned char *buffer_save;

	// Размер файла в байтах.
	extern unsigned long int sizefile; // от 0 и до 4294967295.

	// Здесь размер не закодированных vrle8-данных (в байтах, без заголовка).
	unsigned long int sizedatavrle8; // от 0 и до 4294967295.

void DeCodingVRLE8()
{

	// buffer - Входной массив.
	// buffer_save - Выходной массив.

	unsigned long int addr1, addr2;
	unsigned char bits, cb, tb, offset;

	addr2 = 0;

	// offset - Смещение от начала массива.
	offset = 6; // Пропуск заголовка.

	// Оценить.
	for (addr1 = offset; addr1 < sizefile;)
		{

		// Логическое И (&).
		//
		//   -------------
		//   | x | y | f |
		//   -------------
		//   | 0 | 0 | 0 |
		//   | 0 | 1 | 0 |
		//   | 1 | 0 | 0 |
		//   | 1 | 1 | 1 |
		//   -------------

		// Установить биты 6, 5, 4, 3, 2, 1, 0 в ноль, 7 бит оставить без изменений.
		bits = 128 & buffer[addr1]; // 80H и buffer[addr1]. 128D = 80H.

		// Если 7 бит 0 - неповторяющиеся.
		if (bits == 0)
			{
			// Неповторяющиеся байты.
			// ---

			tb = buffer[addr1++];

			// Порция.
			for (cb = 0; cb < tb; cb++)
				{
				addr1++;
				addr2++;
				}
			}
			else
			{
			// Повторяющиеся байты.
			// ---

			// 7 бит 1 - повторяющиеся.
			// Установить 7 бит в ноль, остальные оставить без изменений.
			tb = 127 & buffer[addr1++]; // 7FH и tb.

			// Порция.
			for (cb = 0; cb < tb; cb++)
				{
				addr2++;
				}
			addr1++;
			}
		}

	// ----------

	// В addr2 размер не закодированных vrle8-данных (без заголовка).
	sizedatavrle8 = addr2;

	// Выделяем память для не закодированных данных.
	buffer_save = malloc(sizedatavrle8);

	// ----------

	addr2 = 0;

	// Декодирование.
	for (addr1 = offset; addr1 < sizefile;)
		{

		// Логическое И (&).
		//
		//   -------------
		//   | x | y | f |
		//   -------------
		//   | 0 | 0 | 0 |
		//   | 0 | 1 | 0 |
		//   | 1 | 0 | 0 |
		//   | 1 | 1 | 1 |
		//   -------------

		// Установить биты 6, 5, 4, 3, 2, 1, 0 в ноль, 7 бит оставить без изменений.
		bits = 128 & buffer[addr1]; // 80H и buffer[addr1]. 128D = 80H.

		// Если 7 бит 0 - неповторяющиеся.
		if (bits == 0)
			{
			// Неповторяющиеся байты.
			// ---

			tb = buffer[addr1++];

			// Порция.
			for (cb = 0; cb < tb; cb++)
				{
				buffer_save[addr2++] = buffer[addr1++];
				}
			}
			else
			{
			// Повторяющиеся байты.
			// ---

			// 7 бит 1 - повторяющиеся.
			// Установить 7 бит в ноль, остальные оставить без изменений.
			tb = 127 & buffer[addr1++]; // 7FH и tb.

			// Порция.
			for (cb = 0; cb < tb; cb++)
				{
				buffer_save[addr2++] = buffer[addr1];
				}
			addr1++;
			}
		}
}
