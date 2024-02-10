#pragma once
#include<iostream>
#include<string>

enum class Sex
{
	male
	, female
};

class Person
{
public:
	Person() : name{ "" }, age{ 0 }, weight{ 0 }, sex{ Sex::male }
	{};
	
	void setName(std::string name);
	void setAge(uint32_t age);
	void setWeight(uint32_t weight);
	void setSex(uint32_t var);

protected:
	void printPerson();

private:
	std::string name;
	uint32_t age, weight;
	Sex sex;
};

class Student : public Person
{
public:
	Student() : yearOfStudy{ 0 }
	{}
	
	void setYearOfStudy(uint32_t year);
	void incYearOfStudy(uint32_t year);

	void printStudent();

private:
	uint32_t yearOfStudy;
};
