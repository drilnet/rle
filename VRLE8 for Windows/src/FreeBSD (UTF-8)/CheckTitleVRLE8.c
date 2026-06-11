
//
// Украина (Ukraine). (C) Демидов С.В.
//

#include <stdio.h>
#include <stdlib.h>

// Проверить заголовок VRLE8.

	// Английский, Русский, Украинский.
	extern unsigned char engrusukr;

void CheckTitleVRLE8(unsigned char* filename)
{
	// Массив для заголовка (VRLE8).
	unsigned char buffer[6] = { 0 };

	// Адрес в массиве buffer.
	unsigned char addrfile;

	// Текущий байт из файла.
	int byte;

	FILE *filed = NULL;
	// Открытие двоичного файла (rb).
	filed = fopen(filename, "rb");

	if (filed == NULL)
		{
		printf("\n");

		switch (engrusukr)
			{
			// English.
			case 0:
				printf("%s", "Attention!");
				printf("\n");

				printf("%s", "Error opening file: ");
				printf("%s", filename);
			break;

			// Русский.
			case 1:
				printf("%s", "Внимание!");
				printf("\n");

				printf("%s", "Ошибка открытия файла: ");
				printf("%s", filename);
			break;

			// Украинский.
			case 3:
				printf("%s", "Увага!");
				printf("\n");

				printf("%s", "Помилка відкриття файлу: ");
				printf("%s", filename);
			break;
			}

		printf("\n");
		printf("\n");

		// Завершение с кодом ошибки 1.
		exit(1);
		}

	addrfile = 0;

	// Чтение только заголовка.
	while (1)
	{
	// Чтение одного байта из файла.
	byte = getc(filed);

	if (byte == EOF)
		{
		if (feof(filed) != 0)
			{
			// Чтение файла закончилось.

			printf("\n");

			// Слишком короткий файл.
			switch (engrusukr)
				{
				// English.
				case 0:
					printf("%s", "Attention!");
					printf("\n");

					printf("%s", "File too short: ");
					printf("%s", filename);
				break;

				// Русский.
				case 1:
					printf("%s", "Внимание!");
					printf("\n");

					printf("%s", "Слишком короткий файл: ");
					printf("%s", filename);
				break;

				// Украинский.
				case 2:
					printf("%s", "Увага!");
					printf("\n");

					printf("%s", "Занадто короткий файл: ");
					printf("%s", filename);
				break;
				}

			printf("\n");
			printf("\n");

			// break;

			// Закрытие файла.
			fclose(filed);

			exit(0);
			}
			else
			{
			// Ошибка чтения из файла.

			printf("\n");

			switch (engrusukr)
				{
				// English.
				case 0:
					printf("%s", "Attention!");
					printf("\n");

					printf("%s", "Error reading file: ");
					printf("%s", filename);
				break;

				// Русский.
				case 1:
					printf("%s", "Внимание!");
					printf("\n");

					printf("%s", "Ошибка чтения файла: ");
					printf("%s", filename);
				break;

				// Украинский.
				case 2:
					printf("%s", "Увага!");
					printf("\n");

					printf("%s", "Помилка читання файлу: ");
					printf("%s", filename);
				break;
				}

			printf("\n");
			printf("\n");

			// Завершение.
			exit(1);
			}
		}

	buffer[addrfile] = byte;

	// 7 - Размер заголовка 6 байт, плюс + 1.
	if (addrfile == 7)
		{
		// Заголовок прочитан, выход.
		break;
		}

	addrfile++;
	}

	// Закрытие файла.
	fclose(filed);

	// Проверяем заголовок!
	if (buffer[0] != 'V' &&
		buffer[1] != 'R' &&
			buffer[2] != 'L' &&
				buffer[3] != 'E' &&
					buffer[4] != '8' // &&
						/*buffer[5] != 0*/)
		{
		// Это не VRLE8 файл.

		printf("\n");

		switch (engrusukr)
			{
			// English.
			case 0:
				printf("%s", "Attention!");
				printf("\n");
				printf("%s", "Input file is not VRLE8!");
			break;

			// Русский.
			case 1:
				printf("%s", "Внимание!");
				printf("\n");
				printf("%s", "Входной файл не VRLE8!");
			break;

			// Украинский.
			case 2:
				printf("%s", "Увага!");
				printf("\n");
				printf("%s", "Вхідний файл не VRLE8!");
			break;
			}

		printf("\n");
		printf("\n");

		exit(0);
		}
}