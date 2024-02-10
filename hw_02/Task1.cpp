#include "Task1.h"

void Person::setName(std::string name)
{
	this->name = name;
}

void Person::setAge(uint32_t age)
{
	this->age = age;
}

void Person::setWeight(uint32_t weight)
{
	this->weight = weight;
}

void Person::setSex(uint32_t var)
{
	if (var == 0)
	{
		sex = Sex::male;
	}
	else
	{
		sex = Sex::female;
	}
}

void Person::printPerson()
{
	std::cout << "���: " << name << std::endl;
	std::cout << "�������: " << age << std::endl;
	std::cout << "���: " << weight << std::endl;
	std::cout << "���: ";
	if (sex == Sex::male)
	{
		std::cout << "�";
	}
	else
	{
		std::cout << "�";
	}
	std::cout << std::endl;
}

void Student::setYearOfStudy(uint32_t year)
{
	yearOfStudy = year;
}

void Student::incYearOfStudy(uint32_t year)
{
	yearOfStudy += year;
}

void Student::printStudent()
{
	printPerson();
	std::cout << "��� ������ ��������: " << yearOfStudy << std::endl;
}
