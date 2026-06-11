
//
// Украина (Ukraine). (C) Демидов С.В.
//

#include <stdio.h>
#include <stdlib.h>

//
// Получаем размер файла.
//

	// Размер файла.
	unsigned long int sizefile; // от 0 и до 4294967295.

	// Английский, Русский, Украинский.
	extern unsigned char engrusukr;

void GetFileSize(unsigned char* filename)
{
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

	sizefile = 0;

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

	// Слишком большой файл (50MB).
	if (sizefile == 50000000)
		{

		// Закрытие файла.
		fclose(filed);

		printf("\n");

		switch (engrusukr)
			{
			// English.
			case 0:
				printf("%s", "Input file is too big!");
			break;

			// Русский.
			case 1:
				printf("%s", "Входной файл слишком большой!");
			break;

			// Украинский.
			case 2:
				printf("%s", "Вхдний файл занадто великий!");
			break;
			}

		printf("\n");
		printf("\n");

		// Завершение.
		exit(1);
		}

	sizefile++;
	}

	// Закрытие файла.
	fclose(filed);
}