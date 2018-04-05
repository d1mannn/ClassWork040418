#include "Header.h"

void main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	FILE *file, *file2;
	int task, answer = 1;
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

		
			case 8:
			{
				/*8.	Файл состоит из k компонент структуры, где каждая компонента содержит две матрицы :
				первая размерности m x n, вторая размерности m x l.Получить k произведений соответствующих матриц
					и записать их во второй файл.Вывести на экран содержимое первого и второго файлов.*/
				int sizeOfStruct = 4 + rand() % 4;
				printf("Кол-во структур = %d\n", sizeOfStruct);
				int m = 4 + rand() % 4;
				int n = 4 + rand() % 4;
				int l = 4 + rand() % 4;


				if ((file = fopen("Case8.txt", "w")) == NULL)
				{
					printf("ERROR\n");
					exit(EXIT_FAILURE);
				}
			
				Matrix *matrix = (Matrix*)calloc(sizeOfStruct, sizeof(Matrix));

				for (size_t i = 0; i < sizeOfStruct; i++)
				{
					(matrix + i)->first = (int*)calloc(m*n, sizeof(int));
					(matrix + i)->second = (int*)calloc(m*l, sizeof(int));
				}


				if (matrix == NULL || matrix->first == NULL || matrix->second == NULL)
				{
					printf("ERRROR\n");
					exit(EXIT_FAILURE);
				}


				printf("\n~~~~~~~~~~~~~~~\nПервая матрица\n");
				StructMatrixCreation1(matrix, &m, &n, &l, &sizeOfStruct);

				printf("\n~~~~~~~~~~~~~~~\nВторая матрица\n");
				StructMatrixCreation2(matrix, &m, &n, &l, &sizeOfStruct);

				MatrixToFile(file, matrix, &m, &n, &l, &sizeOfStruct);
			
				fclose(file);
			

				if ((file = fopen("Case8.txt", "rt")) == NULL)
				{
					printf("ERROR\n");
					exit(EXIT_FAILURE);
				}
				if ((file2 = fopen("Case8_2.txt", "wt")) == NULL)
				{
					printf("ERROR\n");
					exit(EXIT_FAILURE);
				}
				/*for (int i = 0; i < sizeOfStruct; i++)
				{
					fwrite((matrix + i), sizeof(Matrix), 1, file);
				}*/



			//	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

				/*for (size_t i = 0; i < length; i++)
				{

					fscanf(file, "%d", &k); из файла записываем в k;
					sum += k; записывает в сумму значение k;
				}*/

				//	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



				while (!feof(file))
				{
					fputc(fgetc(file), file2);
				}
				fcloseall();

			//	FILE *t1 = fopen("c:\\1.txt", "rt");
			//	FILE *t2 = fopen("c:\\2.txt", "wt");
			//	while (!feof(t1))
			//		fputc(fgetc(t1), t2);
			//	//fcloseall(); убери коментарии и следующие две строчки удали, а если если компилятор будет выдовать ошибки то поставь коментарии на место 
			//	fclose(t1);
			//	fclose(t2);

				for (size_t i = 0; i < sizeOfStruct; i++)
				{
					free((matrix + i)->first);
					free((matrix + i)->second);
				}
				fclose(file);
				fclose(file2);
				free(matrix);
			} break;

			case 10:
			{
				/*10.	Создать бинарный файл со списком о студентах :
				a. фамилия и инициалы студентов;
				b. номер группы;
				c. успеваемость(массив из трех дисциплин по 100 - бальной системе);
				d. размер стипендии.
					e.Вывести список студентов, имеющих по всем предметам положительные оценки и распечатать все сведения о них.
*/
				Students *student;
				int length = 4 + rand() % 4;
				student = (Students*)calloc(length, sizeof(Students));
				if (student == NULL)
				{
					printf("ERROR");
					exit(EXIT_FAILURE);
				}
				NameCreation(student, &length);
				if ((file = fopen("Case10.txt", "w")) != NULL)
				{
					WriteToFile(student, file, &length);
					fclose(file);
				}

				if ((file = fopen("Case10.txt", "rb")) != NULL)
				{
					fseek(file, 0, SEEK_END); // устанавливаем позицию в конец файла
					long lSize = ftell(file); // получаем размер в байтах
					rewind(file); // устанавливаем указатель в конец файла


					char * buffer = (char*)calloc(lSize, sizeof(char));
					if (buffer == NULL)
					{
						fputs("Ошибка памяти\n", stderr);
						exit(EXIT_FAILURE);
					}

					int result = fread(buffer, 1, lSize, file); // считываем файл в буффер
					if (result != lSize)
					{
						fputs("Ошибка чтения", stderr);
						exit(EXIT_FAILURE);
					}
					//теперь содержимое в буфере
					printf("\n\n~~~~~~~~~~~~~~~~~\n\n");
					puts(buffer);
					fclose(file);
					free(buffer);
				}
				free(student);
			} break;
		}

		printf("\n~~~~~~~~~~~~~~~~~~\nДля выхода введите 0 ----> ");
		scanf_s("%d", &answer);

	} while (answer != 0);
}