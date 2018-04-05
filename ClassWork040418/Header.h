#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <time.h>
#include <string.h>
#include "Structs.h"

int TaskNumb();
void DateFilling(struct MyDate * date, int *length);
void FileFilling(FILE * file, MyDate * date, int *length);
void FileSort(NewMyDate * date1, int * length);
void MinMeaning(NewMyDate * date, int * length);



void StructMatrixCreation(Matrix * matrix, int *m, int * n, int * l, int * sizeOfStruct);
void StructMatrixCreation1(Matrix * matrix, int *m, int * n, int * l, int * sizeOfStruct);
void StructMatrixCreation2(Matrix * matrix, int *m, int * n, int * l, int * sizeOfStruct);
void MatrixToFile(FILE *file, Matrix * matrix, int *m, int * n, int * l, int * sizeOfStruct);


void FromIntToChar(int * from, char * to, int *length);
void NameCreation(Students * student, int * countOfstud);
void WriteToFile(Students * student, FILE * file, int * countOfStud);

void FileScan(FILE *file);