
//
// Украина (Ukraine). (C) Демидов С.В.
//

#include <stdio.h>
#include <stdlib.h>

//
// Загрузка файла в память (в массив buffer).
//

	// Здесь загруженный файл.
	unsigned char *buffer;

	// Размер файла (размер загруженного фала в байтах).
	extern unsigned long int sizefile; // от 0 и до 4294967295.

	// Английский, Русский, Украинский.
	extern unsigned char engrusukr;

void LoadFile(unsigned char* filename)
{

	// Выделяем память для массива.
	buffer = malloc(sizefile);

	// Адрес в массиве buffer.
	unsigned long int addrfile; // от 0 и до 4294967295.

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

	addrfile = 0;

	while (1)
	{
	// Чтение одного байта из файла.
	byte = getc(filed);

	if (byte == EOF)
		{
		if (feof(filed) != 0)
			{
			// Чтение файла закончилось.
			break;
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

	buffer[addrfile++] = byte;
	}

	// Закрытие файла.
	fclose(filed);
}