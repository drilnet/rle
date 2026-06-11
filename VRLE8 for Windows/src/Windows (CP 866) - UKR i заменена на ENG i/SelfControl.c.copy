
//
// Украина (Ukraine). (C) Демидов С.В.
//

#include <stdio.h>
#include <stdlib.h>

//
// Самоконтроль.
//

	// Здесь загруженный файл.
	extern unsigned char *buffer;

	// Размер файла в байтах.
	extern unsigned long int sizefile; // от 0 и до 4294967295.

	// Здесь закодированные данные.
	extern unsigned char *$arraycoding8;

	// Здесь размер закодированных данных (в байтах)
	extern unsigned long int sizecoding; // от 0 и до 4294967295.

	// Здесь размер раскодированных данных (в байтах, без заголовка).
	extern unsigned long int sizedatavrle8; // от 0 и до 4294967295.

	// Английский, Русский, Украинский.
	extern unsigned char engrusukr;

void SelfControl()
{

	// $arraycoding8 - Входной массив.
	// arraydecoding8 - Выходной массив.

	unsigned char *arraydecoding8;

	unsigned long int addr1, addr2, z4; // от 0 и до 4294967295.
	unsigned char bits, cb, tb, offset;

	addr2 = 0;

	// offset - Смещение от начала массива.
	offset = 0;

	// Оценить.
	// --------
	for (addr1 = offset; addr1 < sizecoding;)
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
		bits = 128 & $arraycoding8[addr1]; // 80H и $arraycoding8[addr1]. 128D = 80H.

		// Если 7 бит 0 - неповторяющиеся.
		if (bits == 0)
			{
			// Неповторяющиеся байты.
			// ---

			tb = $arraycoding8[addr1++];

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
			tb = 127 & $arraycoding8[addr1++]; // 7FH и tb.

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

	if (sizedatavrle8 != sizefile)
		{

		switch (engrusukr)
			{
			// English.
			case 0:
			printf("%s", "\nCoding with error!\n");
			printf("%s", "Error 1.\n\n");
			break;

			// Русский.
			case 1:
			printf("%s", "\nКодирование с ошибкой!\n");
			printf("%s", "Ошибка 1.\n\n");
			break;

			// Украинский.
			case 2:
			printf("%s", "\nКодування з помилкою!\n");
			printf("%s", "Помилка 1.\n\n");
			break;
			}

		// Закрыть массив buffer.
		free(buffer);
		// Закрыть массив $arraycoding8.
		free($arraycoding8);

		// Завершить работу программы (0 - нормальное завершение).
		exit(0);
		}

	// Выделяем память для не закодированных данных.
	arraydecoding8 = malloc(sizedatavrle8);

	// ----------

	addr2 = 0;

	// Декодирование.
	// --------------
	for (addr1 = offset; addr1 < sizecoding;)
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
		bits = 128 & $arraycoding8[addr1]; // 80H и $arraycoding8[addr1]. 128D = 80H.

		// Если 7 бит 0 - неповторяющиеся.
		if (bits == 0)
			{
			// Неповторяющиеся байты.
			// ---

			tb = $arraycoding8[addr1++];

			// Порция.
			for (cb = 0; cb < tb; cb++)
				{
				arraydecoding8[addr2++] = $arraycoding8[addr1++];
				}
			}
			else
			{
			// Повторяющиеся байты.
			// ---

			// 7 бит 1 - повторяющиеся.
			// Установить 7 бит в ноль, остальные оставить без изменений.
			tb = 127 & $arraycoding8[addr1++]; // 7FH и tb.

			// Порция.
			for (cb = 0; cb < tb; cb++)
				{
				arraydecoding8[addr2++] = $arraycoding8[addr1];
				}
			addr1++;
			}
		}

	// Проверяем (сравниваем) побайтно два массива!
	// --------------------------------------------
	for (z4 = 0; z4 < sizefile; z4++)
		{
		if (buffer[z4] != arraydecoding8[z4])
			{
			switch (engrusukr)
				{
				// English.
				case 0:
				printf("%s", "\nCoding with error!\n");
				printf("%s", "Error 2.\n\n");
				break;

				// Русский.
				case 1:
				printf("%s", "\nКодирование с ошибкой!\n");
				printf("%s", "Ошибка 2.\n\n");
				break;

				// Украинский.
				case 2:
				printf("%s", "\nКодування з помилкою!\n");
				printf("%s", "Помилка 2.\n\n");
				break;
				}

			// Закрыть массив buffer.
			free(buffer);
			// Закрыть массив $arraycoding8.
			free($arraycoding8);
			// Закрыть массив arraydecoding8.
			free(arraydecoding8);

			// Завершить работу программы (0 - нормальное завершение).
			exit(0);
			}
		}

	// Закрыть массив arraydecoding8.
	free(arraydecoding8);
}
