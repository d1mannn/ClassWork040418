
struct MyDate
{
	int day;
	int month;
	int year;
};

struct NewMyDate
{
	int day;
	int month;
	int year;
};

struct Matrix
{
	int *first;
	int *second;
};


//a. фамилия и инициалы студентов;
//b. номер группы;
//c. успеваемость(массив из трех дисциплин по 100 - бальной системе);
//d. размер стипендии.
//e.Вывести список студентов, имеющих по всем предметам положительные оценки и распечатать все сведения о них.

struct StudentsNames
{
	char fName[18];
	char lName[18];
	char mName[18];
};


struct Subjects
{
	int first;
	int second;
	int third;

};
struct Students
{
	StudentsNames Name;
	int group;
	Subjects subject;
	int incomes;
};