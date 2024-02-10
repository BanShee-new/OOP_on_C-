#include<iostream>
#include<windows.h>
#include<vector>
#include<set>
#include"MyLib.h"
#include"Task1.h"
#include"Task3.h"

using namespace std;
using namespace myLib;

void Task1()
{
	cout << "Работа с контейнерным классом:" << endl;
	ArrayInt myArr(4);
	cout << "Создадим массив из 4х элементов:" << endl;
	for (size_t i = 0; i < myArr.getLength(); i++)
	{
		myArr[i] = i;
	}
	myArr.print();
	cout << "Добавим 10 в конец:" << endl;
	myArr.push_back(10);
	myArr.print();
	cout << "Удалим последний элемент:" << endl;
	myArr.pop_back();
	myArr.print();
	cout << "Вставим -1 на 3е место:" << endl;
	myArr.insertBefore(-1, 2);
	myArr.print();
	cout << "Удалим 1й элемент:" << endl;
	myArr.pop_front();
	myArr.print();
	cout << "Вставим -2 на 4е место:" << endl;
	myArr.insertBefore(-2, 3);
	myArr.print();
	cout << "Отсортируем массив:" << endl;
	myArr.sort();
	myArr.print();
	cout << endl;
}

void Task2()
{
	cout << "Поиск кол-ва различных элементов: " << endl;
	vector<int32_t> vecArr{ 1,3,2,4,1,5,3,8,5,9,-7,6,7,5,3,2,4,6,3,1,2 };
	printVect<int32_t>(vecArr);

	set<int32_t> s(&vecArr[0], &vecArr[20]);
	cout << "Различных элементов = ";
	cout << s.size() << endl;
}


void Task3()
{
	cout << "\t\tСыграем в Blackjack!\n\n" << endl << endl;
	int numPlayers = 0;
	while (numPlayers < 1 || numPlayers > 7)
	{
		cout << "На сколько игроков раздаем? (1 - 7): ";
		numPlayers = getUserInput<uint16_t>();
	}
	vector<string> names;
	string name;
	for (int i = 0; i < numPlayers; ++i)
	{
		cout << "Введите имя "<< i + 1 << " игрока: ";
		name = getUserInputTxt();
		names.push_back(name);
	}
	cout << endl;
	// игровой цикл
	Game aGame(names);
	char again = 'y';
	while (again != 'n' && again != 'N')
	{
		aGame.Play();
		cout << "\nХотите сыграть заново? (Y/N): ";
		cin >> again;
	}
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