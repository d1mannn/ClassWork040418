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