#include "Task1.h"

ArrayInt::ArrayInt(int length) : m_length(length)
{
	assert(length >= 0);
	if (length > 0)
		m_arrPointer = m_data = new int[length];
	else
		m_arrPointer = m_data = nullptr;
}

void ArrayInt::erase()
{
	delete[] m_arrPointer;
	m_arrPointer = m_data = nullptr;
	m_length = 0;
}

void ArrayInt::resize(int newLength)
{
	if (newLength == m_length)
		return;
	if (newLength <= 0)
	{
		erase();
		return;
	}
	int* data = new int[newLength];
	if (m_length > 0)
	{
		int elementsToCopy = (newLength > m_length) ? m_length : newLength;
		transferDataAtoB(m_data, data, elementsToCopy);
	}
	delete[] m_arrPointer;
	m_arrPointer = m_data = data;
	m_length = newLength;
}

void ArrayInt::insertBefore(int value, int index)
{
	assert(index >= 0 && index <= m_length);
	int* data = new int[m_length + 1];
	transferDataAtoB(m_data, data, index);
	data[index] = value;
	transferDataAtoB(&m_data[index], &data[index + 1], m_length - index);
	delete[] m_arrPointer;
	m_arrPointer = m_data = data;
	++m_length;
}

void ArrayInt::pop_back()
{
	if (m_length > 0)
		m_data[--m_length] = 0;
	else if (m_arrPointer) 
		erase();
}

void ArrayInt::pop_front()
{
	/*--m_length;
	int* data = new int[m_length];
	transferDataAtoB(&m_data[1], data, m_length);
	delete[] m_data;
	m_data = data;*/
	if (m_length > 0)
	{
		m_data = &m_data[1];
		--m_length;
	}
	else if (m_arrPointer)
		erase();
}

void ArrayInt::sort()
{
	qSort(m_data, 0, m_length - 1);
}

void ArrayInt::qSort(int* s_arr, int first, int last)
{
	if (first < last)
	{
		int left = first, right = last, middle = s_arr[(left + right) / 2];
		do
		{
			while (s_arr[left] < middle) left++;
			while (s_arr[right] > middle) right--;
			if (left <= right)
			{
				int tmp = s_arr[left];
				s_arr[left] = s_arr[right];
				s_arr[right] = tmp;
				left++;
				right--;
			}
		} while (left <= right);
		qSort(s_arr, first, right);
		qSort(s_arr, left, last);
	}
}
void ArrayInt::print() const
{
	myLib::printArr(m_length, true, m_data);
}

int& ArrayInt::operator[](int index)
{
	assert(index >= 0 && index < m_length);
	return m_data[index];
}

void ArrayInt::transferDataAtoB(int* A, int* B, int amount)
{
	for (size_t i = 0; i < amount; i++)
	{
		B[i] = A[i];
	}
}
