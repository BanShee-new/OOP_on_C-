#pragma once
#include<cstdint>
#include<string>
#include<iostream>


class Fraction
{
public:
	Fraction() : wholePart{ 0 }, isNegative{ false }, numerator{ 0 }, denominator{ 1 }, val{ "" }
	{};

	bool read();
	const std::string& get(bool afterOperation = false);

	Fraction operator-() const;

	Fraction& operator+=(const Fraction& fr);
	Fraction& operator-=(const Fraction& fr);
	Fraction& operator*=(const Fraction& fr);
	Fraction& operator/=(const Fraction& fr);

	friend bool operator==(const Fraction& fr1, const Fraction& fr2);
	friend bool operator<(const Fraction& fr1, const Fraction& fr2);

private:
	uint64_t wholePart, numerator, denominator;
	bool isNegative;
	std::string val;

	Fraction(uint64_t whP, uint64_t num, uint64_t den, bool isNeg) : wholePart{ whP }, numerator{ num }, denominator{ den }, isNegative{ isNeg }
	{};
	void cinFail();
	void checkIsNegative(int64_t& val);
	void simplifyAfraction();
};

Fraction operator+(Fraction fr1, const Fraction& fr2);
Fraction operator-(Fraction fr1, const Fraction& fr2);
Fraction operator*(Fraction fr1, const Fraction& fr2);
Fraction operator/(Fraction fr1, const Fraction& fr2);

bool operator==(const Fraction& fr1, const Fraction& fr2);
bool operator!=(const Fraction& fr1, const Fraction& fr2);
bool operator<(const Fraction& fr1, const Fraction& fr2);
bool operator<=(const Fraction& fr1, const Fraction& fr2);
bool operator>(const Fraction& fr1, const Fraction& fr2);
bool operator>=(const Fraction& fr1, const Fraction& fr2);


uint64_t NOD(uint64_t a, uint64_t b);
uint64_t NOK(const uint64_t& a, const uint64_t& b);