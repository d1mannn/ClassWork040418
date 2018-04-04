#include "Header.h"

void main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	FILE *file;
	int task;
	do
	{
		task = TaskNumb();
		switch (task)
		{
			case 1:
			{
				//1.	Дан файл, содержащий различные даты.Каждая дата - это число, месяц и год.Найти самую раннюю дату.
				int length = 4 + rand() % 4;
				MyDate * date;
				date = (MyDate*)calloc(length, sizeof(MyDate));
				if (date == NULL)
				{
					printf("ERROR\n");
					exit(EXIT_FAILURE);
				}
				DateFilling(date, &length);
				if ((file = fopen("Case1.txt", "w")) == NULL)
				{
					printf("ERROR\n");
					exit(EXIT_FAILURE);
				}
				FileFilling(file, date, &length);
				if (fclose(file) == NULL)
				{
					printf("Всё гуд\n");
				}
				free(date);


				if ((file = fopen("Case1.txt", "r")) == NULL)
				{
					printf("ERROR\n");
					exit(EXIT_FAILURE);
				}
				/*int *d, *m, *y;
				d = (int*)calloc(length, sizeof(int));
				m = (int*)calloc(length, sizeof(int));
				y = (int*)calloc(length, sizeof(int));*/
				NewMyDate * date1;
				date1 = (NewMyDate*)calloc(length, sizeof(NewMyDate));
				if (date1 == NULL)
				{
					printf("ERROR\n");
					exit(EXIT_FAILURE);
				}
				for (int i = 0; i < length; i++)
				{
					fscanf(file, "%d.%d.%d\n", &date1[i].day, &date1[i].month, &date1[i].year); // сканируем с файла в структуру т.е. копируем
					printf("%d.%d.%d\n", date1[i].day, date1[i].month, date1[i].year);
				}

				FileSort(date1, &length);
				printf("\nПосле сортировки\n\n");
				for (int i = 0; i < length; i++)
				{
					//fscanf(file, "%d.%d.%d\n", &date1[i].day, &date1[i].month, &date1[i].year); // сканируем с файла в структуру т.е. копируем
					printf("%d.%d.%d\n", date1[i].day, date1[i].month, date1[i].year);
				}
				printf("\n\n");
				MinMeaning(date1, &length);
				fclose(file);
				free(date1);
			} break;
		}
	} while (task > 0);
}