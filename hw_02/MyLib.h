#pragma once
#include<iostream>
#include<string>

using namespace std;
#undef max

namespace myLib
{
	template <typename _Ty>
	inline _Ty GetUserInput(bool allowZero = false);
	std::string GetUserInputTxt();
	unsigned short getUserSelectedTask(unsigned short qtyTask);

	void PrintArr(size_t size, double* Arr);
	void PrintArr(size_t size, float* Arr);
	void PrintArr(size_t size, bool NeedCnt, unsigned short* Arr);
	void PrintArr(size_t size, bool NeedCnt, int* Arr);
	void PrintArr(size_t size, bool NeedCnt, int* Arr, size_t medianPos);

	string getNameFileFromUser(unsigned short indexF);
}

template <typename _Ty>
inline _Ty myLib::GetUserInput(bool allowZero)
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