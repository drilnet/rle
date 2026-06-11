
//
// Украина (Ukraine). (C) Демидов С.В.
//

#include <stdio.h>
#include <stdlib.h>

	// Здесь массив для записи на диск.
	extern unsigned char *buffer_save;

	// Английский, Русский, Украинский.
	extern unsigned char engrusukr;

void SaveFile(unsigned char* filename, unsigned long int size)
{
	// Для buffer_save (адрес, индекс).
	unsigned long int addr_bs;

	// byte - запись байта.
	int byte;

	FILE *filed = NULL;
	// Открытие двоичного файла (wb).
	filed = fopen(filename, "wb");

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
			case 2:
				printf("%s", "Увага!");
				printf("\n");

				printf("%s", "Помилка вiдкриття файлу: ");
				printf("%s", filename);
			break;
			}

		printf("\n");
		printf("\n");

		// Завершение с кодом ошибки 1.
		exit(1);
		}

	// Записываем данные.
	for (addr_bs = 0; addr_bs < size; addr_bs++)
		{
		byte = buffer_save[addr_bs];

		// Запись одного байта в файл.
		byte = putc(byte, filed);

		if (byte == EOF)
			{
			// Ошибка записи.
			printf("\n");

			switch (engrusukr)
				{
				// English.
				case 0:
					printf("%s", "Attention!");
					printf("\n");

					printf("%s", "File write error: ");
					printf("%s", filename);
				break;

				// Русский.
				case 1:
					printf("%s", "Внимание!");
					printf("\n");

					printf("%s", "Ошибка записи файла: ");
					printf("%s", filename);
				break;

				// Украинский.
				case 2:
					printf("%s", "Увага!");
					printf("\n");

					printf("%s", "Помилка запису файлу: ");
					printf("%s", filename);
				break;
				}

			printf("\n");
			printf("\n");

			// Завершение с ошибкой..
			exit(1);
			}
		}

	// Закрытие файла.
	fclose(filed);
}