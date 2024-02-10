#pragma once
#include<string>

class Fruit
{
public:
	Fruit(std::string name, std::string colour) : name(name), colour(colour)
	{};
	
	std::string getName() { return name; };
	std::string getColor() { return colour; };

private:
	std::string name, colour;
};

class Apple : public Fruit
{
public:
	Apple(std::string colour, std::string name = "") : Fruit(name + "apple", colour)
	{};
};

class Banana : public Fruit
{
public:
	Banana() : Fruit("banana", "yellow")
	{};
};

class GrannySmith : public Apple
{
public:
	GrannySmith() : Apple("green", "Granny Smith ")
	{};
};