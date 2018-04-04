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