#include<iosfwd>
#include<windows.h>
#include<memory>
#include<ctime>
#include"MyLib.h"
#include"Task1.h"
#include"Task2.h"
#include"Task3-4-5.h"

using namespace std;
using namespace myLib;

void Task1()
{
	cout << "Работа с классом Date:" << endl << endl;
	time_t now = time(0);
	tm currTime;
	gmtime_s(&currTime, &now);
	
	auto today = make_unique<Date>(currTime.tm_mday, currTime.tm_mon + 1, currTime.tm_year + 1900);
	unique_ptr<Date> date;
	
	cout << "Сегодняшняя дата: " << endl;
	cout << "День: " << today.get()->getDay() << endl;
	cout << "Месяц: " << today.get()->getMonth() << endl;
	cout << "Год: " << today.get()->getYear() << endl << endl;
	cout << *today << endl;

	cout << "объект today: " << (static_cast<bool>(today) ? "NOT null\n" : "null\n");
	cout << "объект date: " << (static_cast<bool>(date) ? "NOT null\n" : "null\n");
	cout << "Переместим ресурс today -> date" << endl;
	date = move(today);
	cout << "объект today: " << (static_cast<bool>(today) ? "NOT null\n" : "null\n");
	cout << "объект date: " << (static_cast<bool>(date) ? "NOT null\n" : "null\n");

}

void Task2()
{
	cout << "Поиск максимальной даты:" << endl << endl;
	auto date1 = make_shared<Date>(12,5,2021);
	auto date2 = make_shared<Date>(13,5,2021);
	cout << "date1: " << *date1 << endl;
	cout << "date2: " << *date2 << endl;
	auto dateMax = maxDate(date1, date2);
	cout << "dateMax: " << *dateMax << endl;
	cout << "Проверка на существоание исходных объектов:" << endl;
	cout << "date1: " << *date1 << endl;
	cout << "date2: " << *date2 << endl << endl;

	cout << "Меняем местами date1 и date2: " << endl;
	swapDate(date1, date2);
	cout << "date1: " << *date1 << endl;
	cout << "date2: " << *date2 << endl << endl;
	
	cout << "Проверяем что dateMax остался верный: " << endl;
	cout << "dateMax: " << *dateMax << endl;

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
	names.reserve(numPlayers);
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