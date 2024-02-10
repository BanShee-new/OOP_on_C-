#pragma once
#include<iostream>
#include<string>

using namespace std;
#undef max

namespace myLib
{
	template <typename _Ty>
	inline _Ty getUserInput(bool allowZero = false);
	std::string getUserInputTxt();
	unsigned short getUserSelectedTask(unsigned short qtyTask);

	void printArr(size_t size, double* Arr);
	void printArr(size_t size, float* Arr);
	void printArr(size_t size, bool NeedCnt, unsigned short* Arr);
	void printArr(size_t size, bool NeedCnt, int* Arr);
	void printArr(size_t size, bool NeedCnt, int* Arr, size_t medianPos);

	string getNameFileFromUser(unsigned short indexF);
}

template <typename _Ty>
inline _Ty myLib::getUserInput(bool allowZero)
{
	while (true)
	{
		_Ty input;
		cin >> input;
		if (cin.fail() || (input <= 0) && !allowZero || (input < 0) && allowZero)
		{
			cout << "Ошибка ввода, повторите ввод: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return input;
		}
	}
}