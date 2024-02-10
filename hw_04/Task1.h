#pragma once

#include <cassert>
#include "MyLib.h"

class ArrayInt
{
public:
	ArrayInt() : m_length(0), m_data(nullptr), m_arrPointer(nullptr)
	{}
	ArrayInt(int length);	
	~ArrayInt() { delete[] m_arrPointer; };

	void erase();	
	int getLength() { return m_length; };
	void resize(int newLength);
	void insertBefore(int value, int index);
	void push_back(int value) { insertBefore(value, m_length); }
	void pop_back();
	void pop_front();
	void sort();
	void print() const;

	int& operator[](int index);

private:
	int m_length;
	int* m_data;
	int* m_arrPointer;

	void transferDataAtoB(int* A, int* B, int amount);
	void qSort(int* s_arr, int first, int last);
};