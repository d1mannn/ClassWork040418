#include "Header.h"

int TaskNumb()
{
	printf("Введите номер задания - ");
	int task;
	scanf_s("%d", &task);
	return task;
}

void DateFilling(MyDate * date, int *length)
{
	for (int i = 0; i < *length; i++)
	{
		date[i].day = 1 + rand() % 20;
		date[i].month = 1 + rand() % 11;
		date[i].year = 1990 + rand() % 25;
	}
}

void FileFilling(FILE * file, MyDate * date, int *length)
{
	for (int i = 0; i < *length; i++)
	{
		//fscanf(file, "%d.%d.%d\n", date[i].day, date[i].month, date[i].year);
		fprintf(file, "%d.%d.%d\n", date[i].day, date[i].month, date[i].year); // распечтываю информацию в файл. т.е. копирую откуда то в файл
	}
}

void FileSort(NewMyDate * date1, int * length)
{
	NewMyDate temp;
	for (int i = 0; i < *length; i++)
	{
		for (int j = *length - 1; j > 0; j--)
		{
			if (date1[j - 1].year > date1[j].year)
			{
				temp = date1[j - 1];
				date1[j - 1] = date1[j];
				date1[j] = temp;
			}
		}
	}
}

void MinMeaning(NewMyDate * date, int * length)
{
	int min = date[0].year;
	int index = 0;
	for (int i = 0; i < *length; i++)
	{
		if (date[i].year < min)
		{
			min = date[i].year;
			index = i;
		}
	}
	printf("Минимальная дата: %d.%d.%d\n", date[index].day, date[index].month, date[index].year);
}

void StructMatrixCreation(Matrix * matrix, int *m, int * n, int * l, int * sizeOfStruct)
{
	int cc = 0;
	for (int j = 0; j < *m**n; j++)
	{
		cc++;
		matrix->first[j] = -10 + rand() % 20;
		printf("%d\t", matrix->first[j]);
		if (cc == *m)
		{
			cc = 0;
			printf("\n");
		}
	}
}

void StructMatrixCreation1(Matrix * matrix, int *m, int * n, int * l, int * sizeOfStruct)
{	
	//int cc = 0;
	for (int i = 0; i < *sizeOfStruct; i++)
	{	
		printf("\n%d-я структур:\n", i + 1);
		for (int j = 0; j < *m**n; j++)
		{
		//	cc++;
			(matrix+i)->first[j] = -10 + rand() % 20;
		/*	printf("%d\t", (matrix + i)->first[j]);
			if (cc == *m)
			{
				cc = 0;
				printf("\n");
			}*/
		}
	}
}

void StructMatrixCreation2(Matrix * matrix, int *m, int * n, int * l, int * sizeOfStruct)
{
	//int cc = 0;
	for (int i = 0; i < *sizeOfStruct; i++)
	{
		printf("\n%d-я структур:\n", i + 1);
		for (int j = 0; j < *m**n; j++)
		{
		//	cc++;
			(matrix + i)->second[j] = -10 + rand() % 20;
			/*printf("%d\t", (matrix + i)->first[j]);
			if (cc == *m)
			{
				cc = 0;
				printf("\n");
			}*/
		}
	}
}

void MatrixToFile(FILE *file, Matrix * matrix, int *m, int * n, int * l, int * sizeOfStruct)
{	
	int cc = 0;
	for (int i = 0; i < *sizeOfStruct; i++)
	{	
		fprintf(file, "\nСтруктура %d-я, Матрица № 1: \n\n", i + 1);
		for (int j = 0; j < *m * *n; j++)
		{	
			cc++;
			fprintf(file, "%d\t", matrix[i].first[j]);
			if (cc == *m)
			{
				cc = 0;
				fprintf(file,"\n");
			}
		}
	}

	cc = 0;
	fprintf(file, "\n~~~~~~~~~~~~\n");
	for (int i = 0; i < *sizeOfStruct; i++)
	{
		fprintf(file, "\nСтруктура %d-я, Матрица № 2: \n\n", i + 1);
		for (int j = 0; j < *m * *n; j++)
		{
			cc++;
			fprintf(file, "%d\t", matrix[i].first[j]);
			if (cc == *m)
			{
				cc = 0;
				fprintf(file, "\n");
			}
		}
	}
}

void FromIntToChar(int * from, char * to, int *length)
{
	for (int i = 0; i < *length; i++)
	{	
		to[i] = (char)from[i];
	}
	to[0] = toupper(to[0]);
	to[*length] = '\0';
}
void NameCreation(Students * student, int * countOfstud)
{
	int lName[18];
	int fName[18];
	int mName[18];
	int length;
	for (int i = 0; i < *countOfstud; i++)
	{
		length = 5 + rand() % 5;
		for (int i = 0; i < length; i++)
		{
			lName[i] = 97 + rand() % 26;
		}
		FromIntToChar(lName, student[i].Name.lName, &length);
		length = 5 + rand() % 5;
		for (int i = 0; i < length; i++)
		{
			fName[i] = 97 + rand() % 26;
		}
		FromIntToChar(fName, student[i].Name.fName, &length);
		length = 5 + rand() % 5;
		for (int i = 0; i < length; i++)
		{
			mName[i] = 97 + rand() % 26;
		}
		FromIntToChar(mName, student[i].Name.mName, &length);
		
		student[i].group = 1 + rand() % 5;
		student[i].incomes = 10000 + rand() % 25000;
		student[i].subject.first = 5 + rand() % 5;
		student[i].subject.second = 5 + rand() % 5;
		student[i].subject.third = 5 + rand() % 5;
	}
}

void WriteToFile(Students * student, FILE * file, int * countOfStud)
{
	for (int i = 0; i < *countOfStud; i++)
	{	
		if (i == *countOfStud - 1)
		{
			fprintf(file, "%d)\t%s %s %s - Группа %d\n\tОценки по предметам:\n\tМатем: %d\n\tФизика: %d\n\tХимия: %d\n\tСтипендия: %d",
				i + 1, student[i].Name.fName, student[i].Name.mName, student[i].Name.lName, student[i].group, student[i].subject.first,
				student[i].subject.second, student[i].subject.third, student[i].incomes);
		}
		
		else
		{
			fprintf(file, "%d)\t%s %s %s - Группа %d\n\tОценки по предметам:\n\tМатем: %d\n\tФизика: %d\n\tХимия: %d\n\tСтипендия: %d\n",
				i + 1, student[i].Name.fName, student[i].Name.mName, student[i].Name.lName, student[i].group, student[i].subject.first,
				student[i].subject.second, student[i].subject.third, student[i].incomes);
		}
	}
}

void FileScan(FILE *file)
{
	char lname[20];
	fscanf(file, "%s", &lname);
	puts(lname);
}

