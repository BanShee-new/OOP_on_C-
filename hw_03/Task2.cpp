#include"Task2.h"
#include<iostream>

using namespace std;

void Car::carCreated()
{
	cout << "Создан класс Car: Company = '" << company << "', Model = '" << model << "'" << endl;
}

Car::~Car()
{
	cout << "Класс Car " << company << " " << model << " разрушен" << endl;
}

void PassengerCar::pasCarCreated()
{
	cout << "Создан класс PassengerCar: Company = '" << company << "', Model = '" << model << "'" << endl;
}

PassengerCar::~PassengerCar()
{
	cout << "Класс PassengerCar " << company << " " << model << " разрушен" << endl;
}

void Bus::busCreated()
{
	cout << "Создан класс Bus: Company = '" << company << "', Model = '" << model << "'" << endl;
}

Bus::~Bus()
{
	cout << "Класс Bus " << company << " " << model << " разрушен" << endl;
}

void Minivan::minivanCreated()
{
	cout << "Создан класс Minivan: Company = '" << company << "', Model = '" << model << "'" << endl;
}

Minivan::~Minivan()
{
	cout << "Класс Minivan " << company << " " << model << " разрушен" << endl;
}
