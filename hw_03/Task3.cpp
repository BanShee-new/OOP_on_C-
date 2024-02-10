#include"Task3.h"

bool Fraction::read()
{
	int64_t input;
	using std::cin;
	cin >> input;
	if (cin.fail())
	{
		cinFail();
	}
	else
	{
		if (cin)
		{
			if (cin.peek() == '\n')
			{
				checkIsNegative(input);
				wholePart = input;
			}
			else
			{
				if (cin.peek() == ' ')
				{
					cin.ignore();
					checkIsNegative(input);
					wholePart = input;
					cin >> input;
					if (cin.fail())
					{
						cinFail();
						return false;
					};
				}
				else
				{
					wholePart = 0;
					isNegative = false;
				}
				if (cin.peek() == '/')
				{
					cin.ignore();
					checkIsNegative(input);
					numerator = input;
					cin >> input;
					if (cin.fail())
					{
						cinFail();
						return false;
					};
					if (input == 0)
					{
						std::cout << "Нулевой делитель невозможен! Повторите ввод: ";
						denominator = 1;
						return false;
					}
					checkIsNegative(input);
					denominator = input;
				}
				else
				{
					denominator = 1;
				}
			}
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			simplifyAfraction();
			return true;
		}
	}
	return false;
}

const std::string& Fraction::get(bool afterOperation)
{
	val = "";
	if (isNegative)
	{
		if (afterOperation) val += "(";
		val += "-";
	}
	if (wholePart)
	{
		val += std::to_string(wholePart) + " ";
	}
	if (numerator && (denominator != 1))
	{
		val += std::to_string(numerator) + "/" + std::to_string(denominator);
	}
	if (isNegative && afterOperation) val += ")";
	return val;
}

Fraction Fraction::operator-() const
{
	return Fraction(wholePart, numerator, denominator, !isNegative);
}

Fraction& Fraction::operator+=(const Fraction& fr)
{
	int64_t nok = NOK(denominator, fr.denominator);
	uint64_t thisNum, frNum;
	bool resFractNegativ;
	if (isNegative ^ fr.isNegative)
	{
		if (wholePart >= fr.wholePart)
		{
			wholePart -= fr.wholePart;
		}
		else
		{
			wholePart = fr.wholePart - wholePart;
			isNegative = fr.isNegative;
		}
		
		thisNum = numerator * nok / denominator;
		frNum = fr.numerator * nok / fr.denominator;
		if (thisNum >= frNum)
		{
			numerator = thisNum - frNum;
			resFractNegativ = isNegative;
		}
		else
		{
			numerator = frNum - thisNum;
			resFractNegativ = fr.isNegative;
		}
		
		if (isNegative ^ resFractNegativ)
		{
			if (wholePart > 0)
			{
				wholePart--;
				numerator = nok - numerator;
			}
			else
			{
				isNegative = resFractNegativ;
			}
		}
	}
	else
	{
		wholePart += fr.wholePart;
		numerator = numerator * nok / denominator + fr.numerator * nok / fr.denominator;
	}	
	denominator = nok;
	simplifyAfraction();
	return *this;
}

Fraction& Fraction::operator-=(const Fraction& fr)
{
	*this += -fr;
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& fr)
{
	uint64_t newFrNum, newFrDen, nod;
	if (wholePart)
	{
		numerator += wholePart * denominator;
		wholePart = 0;
	}
	if (fr.wholePart)
	{
		newFrNum = fr.numerator + fr.denominator * fr.wholePart;
	}
	else
	{
		newFrNum = fr.numerator;
	}
	nod = NOD(numerator, fr.denominator);
	if (nod > 1)
	{
		numerator /= nod;
		newFrDen = fr.denominator / nod;
	}
	else
	{
		newFrDen = fr.denominator;
	}
	nod = NOD(denominator, newFrNum);
	if (nod > 1)
	{
		denominator /= nod;
		newFrNum /= nod;
	}
	numerator *= newFrNum;
	denominator *= newFrDen;
	if (fr.isNegative)
	{
		isNegative = !isNegative;
	}
	simplifyAfraction();
	return *this;
}

Fraction& Fraction::operator/=(const Fraction& fr)
{
	uint64_t newDen;
	if (fr.numerator)
	{
		newDen = fr.numerator;
		if (fr.wholePart)
		{
			newDen += fr.wholePart * fr.denominator;
		}
	}
	else
	{
		if (fr.wholePart)
		{
			newDen = fr.wholePart * fr.denominator;
		}
		else
		{
			newDen = 1;
		}
	}		
	*this *= Fraction(0, fr.denominator, newDen, fr.isNegative);
	return *this;
}

void Fraction::cinFail()
{
	using std::cin;
	using std::cout;

	cout << "Ошибка ввода, повторите ввод: ";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Fraction::checkIsNegative(int64_t& val)
{
	if (val < 0)
	{
		isNegative = !isNegative;
		val = -val;
	}
}

void Fraction::simplifyAfraction()
{
	if (numerator >= denominator)
	{
		wholePart += numerator / denominator;
		numerator %= denominator;
	}
	uint64_t nod = NOD(numerator, denominator);
	if (nod > 1)
	{
		numerator /= nod;
		denominator /= nod;
	}
}


Fraction operator+(Fraction fr1, const Fraction& fr2)
{
	fr1 += fr2;
	return fr1;
};

Fraction operator-(Fraction fr1, const Fraction& fr2)
{
	fr1 -= fr2;
	return fr1;
};

Fraction operator*(Fraction fr1, const Fraction& fr2)
{
	fr1 *= fr2;
	return fr1;
};

Fraction operator/(Fraction fr1, const Fraction& fr2)
{
	fr1 /= fr2;
	return fr1;
};

bool operator==(const Fraction& fr1, const Fraction& fr2)
{
	return ((fr1.isNegative  == fr2.isNegative)	&&
			(fr1.wholePart	 == fr2.wholePart)	&&
			(fr1.numerator	 == fr2.numerator)	&&
			(fr1.denominator == fr2.denominator));
}

bool operator!=(const Fraction& fr1, const Fraction& fr2)
{
	return !(fr1 == fr2);
}

bool operator<(const Fraction& fr1, const Fraction& fr2)
{
	uint64_t nok, newFr1Num, newFr2Num;
	if (fr1.isNegative && !fr2.isNegative) return true;
	else if (!fr1.isNegative && fr2.isNegative) return false;
	else
	{
		if (fr1.wholePart > fr2.wholePart) return fr1.isNegative;
		else if (fr1.wholePart < fr2.wholePart) return !fr1.isNegative;
		else
		{
			nok = NOK(fr1.denominator, fr2.denominator);
			newFr1Num = nok / fr1.denominator * fr1.numerator;
			newFr2Num = nok / fr2.denominator * fr2.numerator;
			if (newFr1Num > newFr2Num) return fr1.isNegative;
			else if (newFr1Num < newFr2Num) return !fr1.isNegative;
			else return false;
		}
	}
}

bool operator<=(const Fraction& fr1, const Fraction& fr2)
{
	return !(fr1 > fr2);
}

bool operator>(const Fraction& fr1, const Fraction& fr2)
{
	return fr2 < fr1;
};

bool operator>=(const Fraction& fr1, const Fraction& fr2)
{
	return !(fr1 < fr2);
};

uint64_t NOD(uint64_t a, uint64_t b)
{
	while (a && b)
	{
		if (a > b)
		{
			a %= b;
		}
		else
		{
			b %= a;
		}
	}
	return a + b;
};

uint64_t NOK(const uint64_t& a, const uint64_t& b)
{
	return a * b / NOD(a, b);
};