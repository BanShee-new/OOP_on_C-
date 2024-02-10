#include<iostream>
#include<windows.h>
#include<vector>
#include<set>
#include"MyLib.h"
#include"Task2.h"
#include"Task3-4-5.h"

using namespace std;
using namespace myLib;

void Task1()
{
	cout << "Ввод числа int с защитой от \"Дурака\":" << endl;
	int64_t a = getUserInput<int64_t>(true, true, true);
	cout << "Вы ввели: " << a << endl;
}

void Task2()
{
	cout << "Работа с собственным манипулятором endll:" << endl;
	cout << "Привет" << endll;
	cout << "После endll" << endl;
}

void Task3()
{
	cout << "\t\tСыграем в Blackjack!" << endl << endl;
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
		cout << "Введите имя " << i + 1 << " игрока: ";
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