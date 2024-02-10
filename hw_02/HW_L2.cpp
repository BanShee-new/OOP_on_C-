#include<iostream>
#include<windows.h>
#include"MyLib.h"
#include"Task1.h"
#include"Task2.h"
#include"Task3.h"

using namespace std;
using namespace myLib;

#define SIZE_ARRAY 100

void Task1()
{
	Student arrStudent[SIZE_ARRAY];
	uint16_t count = 0, number = 0, input = 1;
	do
	{
		if (input == 1)
		{
			cout << "Создаем студента:" << endl << endl;
			cout << "Введите Имя: ";
			arrStudent[count].setName(GetUserInputTxt());
			cout << "Введите возраст: ";
			arrStudent[count].setAge(GetUserInput<uint32_t>());
			cout << "Введите вес: ";
			arrStudent[count].setWeight(GetUserInput<uint32_t>());
			cout << "Введите 0 - Мужской, 1 - Женский: ";
			arrStudent[count].setSex(GetUserInput<uint32_t>(true));
			cout << "Введите год начала обучения: ";
			arrStudent[count].setYearOfStudy(GetUserInput<uint32_t>());
			count++;
		}
		else
		{
			arrStudent[number].printStudent();
		}
		cout << endl;
		cout << "0 - Выход" << endl;
		cout << "1 - Ввод нового студента" << endl;
		cout << "2 - Вывести инфо. о студенте" << endl;
		cout << "Ввод: ";
		input = GetUserInput<uint32_t>(true);
		if (input == 2)
		{
			cout << endl;
			cout << "Введите номер студента, всего "<< count << ": " << endl;
			number = GetUserInput<uint32_t>() - 1;
		}
	} while (input != 0);	
}

void Task2()
{
	cout << "Работа с классом Фрукты:" << endl << endl;
	
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
}

void Task3()
{
	cout << "Работа с классом Колоды карт:" << endl << endl;

	Deck deck;
}


int main()
{
	setlocale(LC_ALL, "RU");
	//srand(time(0));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	unsigned short taskNumber = 0;
	while (true)
	{
		taskNumber = getUserSelectedTask(3);
		switch (taskNumber)
		{
		case 1: Task1();
			break;
		case 2: Task2();
			break;
		case 3: Task3();
			break;
		}
		cout << endl;
	}
}