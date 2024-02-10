#pragma once
#include<string>
#include<cstdio>

class Car
{
public:
	Car() : company{ "no name" }, model{ "other car" }
	{
		carCreated();
	};
	Car(const std::string& cmp) : company{ cmp }, model{ "other car" }
	{
		carCreated(); 
	};
	Car(const std::string& cmp, const std::string& mdl) : company{cmp}, model{mdl}
	{
		carCreated();
	};

	void carCreated();

	~Car();
protected:
	std::string company, model;
};

class PassengerCar : virtual public Car
{
public:
	PassengerCar(const std::string& cmp) : Car(cmp, "other passenger car")
	{
		pasCarCreated();
	};
	PassengerCar(const std::string& cmp, const std::string& mdl) : Car(cmp, mdl)
	{
		pasCarCreated();
	};

	void pasCarCreated();

	~PassengerCar();
private:
};

class Bus : virtual public Car
{
public:
	Bus(const std::string& cmp) : Car(cmp, "other bus")
	{
		busCreated();
	};
	Bus(const std::string& cmp, const std::string& mdl) : Car(cmp, mdl)
	{
		busCreated();
	};

	void busCreated();

	~Bus();
private:
};

class Minivan : public PassengerCar, Bus
{
public:
	Minivan(const std::string& cmp) : Car(cmp, "other bus"), PassengerCar(cmp), Bus(cmp)
	{
		minivanCreated();
	};
	Minivan(const std::string& cmp, const std::string& mdl) : Car(cmp, mdl), PassengerCar(cmp), Bus(cmp)
	{
		minivanCreated();
	};

	void minivanCreated();

	~Minivan();
private:
};