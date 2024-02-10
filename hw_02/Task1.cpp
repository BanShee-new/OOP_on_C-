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
	std::cout << "Имя: " << name << std::endl;
	std::cout << "Возраст: " << age << std::endl;
	std::cout << "Вес: " << weight << std::endl;
	std::cout << "Пол: ";
	if (sex == Sex::male)
	{
		std::cout << "М";
	}
	else
	{
		std::cout << "Ж";
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
	std::cout << "Год начала обучения: " << yearOfStudy << std::endl;
}
