#include<iosfwd>
#include<windows.h>
#include<memory>
#include<ctime>
#include"MyLib.h"
#include"Task1.h"
#include"Task2.h"
#include"Task3.h"

using namespace std;
using namespace myLib;

void Task1()
{
	cout << "Работа с Функцией div:" << endl << endl;
	int64_t a, b;
	double_t aa, bb, result;
	try
	{
		cout << "введите целое число a = ";
		a = getUserInput<int64_t>(true, true);
		cout << "введите целое число b = ";
		b = getUserInput<int64_t>(true, true);
		result = div<int64_t>(a, b);
		cout << a << " / " << b << " = " << result << endl;

		cout << "введите дробное число a = ";
		aa = getUserInput<double_t>(true, true);
		cout << "введите дробное число b = ";
		bb = getUserInput<double_t>(true, true);
		result = div<double_t>(aa, bb);
		cout << aa << " / " << bb << " = " << result << endl;
	}
	catch (const std::exception &exception)
	{
		cerr << "Возникла ошибка: " << exception.what() << endl;
	}
	catch (...)
	{
		cerr << "Возникла не известная ошибка!" << endl;
	}
}

void Task2()
{
	cout << "Работа с классом Bar:" << endl << endl;
	Bar bar;
	double_t n;
	try
	{
		do
		{
			cout << "Введите n = ";
			n = getUserInput<double_t>(true, true);
			bar.set(n);
			cout << endl;
		} while (n != 0);		
	}
	catch (const Ex& ex)
	{
		cerr << "Возникла ошибка: Ex с параметром (" << ex.what() << ")" << endl;
	}
	catch (...)
	{
		cerr << "Возникла не известная ошибка!" << endl;
	}
}

void Task3()
{
	system("cls");
	Robot rb;
	char c;
	do
	{
		cout << "Работа с классом Робот:" << endl << endl;
		rb.print();
		cout << endl << "Для перемещения используйте WASD, для выхода Q" << endl;
		c = getUserInputKey();		
		system("cls");
		try
		{
			switch (c)
			{
			case 'd':
			case 'D':
				rb.move(Direction::RIGHT);
				break;
			case 'a':
			case 'A':
				rb.move(Direction::LEFT);
				break;
			case 'w':
			case 'W':
				rb.move(Direction::UP);
				break;
			case 's':
			case 'S':
				rb.move(Direction::DOWN);
				break;
			case 'q':
			case 'Q':
				break;
			default:
				rb.move(Direction::other);
			}
		}
		catch (const OffTheField& ex)
		{
			cerr << "Попытка выхода за пределы поля! " << ex.what() << endl;
		}
		catch (const IllegalCommand& ex)
		{
			cerr << "Указано неизвестное направление!" << endl;
		}
		catch (...)
		{
			cerr << "Неизвестная ошибка!" << endl;
		}
	} while (c != 'q' && c != 'Q');
	

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