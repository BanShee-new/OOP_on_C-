#include<iostream>
#include<windows.h>
#include"MyLib.h"
#include"Task1.h"
#include"Task2.h"
#include"Task3.h"
#include"Task4.h"

using namespace std;
using namespace myLib;
using namespace figures;

void Task1()
{
	uint16_t val = 0;
	cout << "Считаем площади фигур:";
	do
	{		
		cout << endl << endl;
		cout << "Выберите фигуру:" << endl
			<< "1 - Параллелограмм" << endl
			<< "2 - Прямоугольник" << endl
			<< "3 - Квадрат" << endl
			<< "4 - Ромб" << endl
			<< "5 - Круг" << endl << endl
			<< "0 - Выход" << endl << endl
			<< "Ввод: ";
		val = getUserInput<uint16_t>(true);
		cout << endl;

		uint16_t a, b, h, d1, d2, r;
		Figure* rFig = nullptr;

		switch (val)
		{
		case 1 :
			cout << "Параллелограмм:" << endl;
			cout << "Основание a = ";
			a = getUserInput<uint16_t>();
			cout << "Высота h = ";
			h = getUserInput<uint16_t>();				
			rFig = new Parallelogram(a, h);			
			break;
		case 2:
			cout << "Прямоугольник:" << endl;
			cout << "Длинна a = ";
			a = getUserInput<uint16_t>();
			cout << "Ширина b = ";
			b = getUserInput<uint16_t>();				
			rFig = new figures::Rectangle(a, b);
			break;
		case 3:
			cout << "Квадрат:" << endl;
			cout << "Длинна a = ";
			a = getUserInput<uint16_t>();
			rFig = new Square(a);
			break;
		case 4:
			cout << "Ромб:" << endl;
			cout << "Диагональ d1 = ";
			d1 = getUserInput<uint16_t>();
			cout << "Диагональ d2 = ";
			d2 = getUserInput<uint16_t>();
			rFig = new Rhombus(d1, d2);
			break;
		case 5:
			cout << "Круг:" << endl;
			cout << "Радиус r = ";
			r = getUserInput<uint16_t>();
			rFig = new Circle(r);
			break;
		}

		if (val)
		{
			rFig->printArea();
			delete rFig;
		}		
	} while (val != 0);
	
	
}

void Task2()
{
	cout << "Работа с классом Car и его наследниками:" << endl << endl;
	Car car;
	PassengerCar pasCar("BMW", "X5");
	Bus bus("Volvo", "9700");
	Minivan minivan("Chevrolet", "Orlando");
}

void Task3()
{
	cout << "Работа с классом Дроби:" << endl << endl;

	Fraction fr1, fr2, frResult;
	cout << "Введите 1ю дробь: ";
	while (!fr1.read());
	cout << "Введите 2ю дробь: ";
	while (!fr2.read());

	cout << boolalpha;
	
	frResult = fr1 + fr2;
	cout << fr1.get() << " + " << fr2.get(true) << " = " << frResult.get() << endl;
	frResult = fr1 - fr2;
	cout << fr1.get() << " - " << fr2.get(true) << " = " << frResult.get() << endl;
	frResult = fr1 * fr2;
	cout << fr1.get() << " * " << fr2.get(true) << " = " << frResult.get() << endl;
	frResult = fr1 / fr2;
	cout << fr1.get() << " : " << fr2.get(true) << " = " << frResult.get() << endl << endl;

	cout << fr1.get() << " <  " << fr2.get(true) << " is " << (fr1 <  fr2) << endl;
	cout << fr1.get() << " <= " << fr2.get(true) << " is " << (fr1 <= fr2) << endl;
	cout << fr1.get() << " >  " << fr2.get(true) << " is " << (fr1 >  fr2) << endl;
	cout << fr1.get() << " >= " << fr2.get(true) << " is " << (fr1 >= fr2) << endl;
	cout << fr1.get() << " =  " << fr2.get(true) << " is " << (fr1 == fr2) << endl;
	cout << fr1.get() << " <> " << fr2.get(true) << " is " << (fr1 != fr2) << endl;
}

void Task4()
{
	cout << "Работа с классом Колоды карт:" << endl << endl;

	Card card;
	card.setValue(Denomination::J, Suit::diamonds);
	cout << "кол-во очков: " << card.getValue() << endl;
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
		taskNumber = getUserSelectedTask(4);
		switch (taskNumber)
		{
		case 1: Task1();
			break;
		case 2: Task2();
			break;
		case 3: Task3();
			break;
		case 4: Task4();
			break;
		}
		cout << endl;
	}
}