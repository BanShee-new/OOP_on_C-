#pragma once
#include <cstdint>
#include <stdexcept>
#include <string>
#include <iostream>

#define SIZE_FIELD 10


struct Pos
{
	int16_t x, y;
};

enum class Direction
{
	RIGHT, LEFT, DOWN, UP, other
};

class OffTheField : public std::exception 
{
public:	
	OffTheField(Pos pos, Direction dir)
	{
		error = "Текущая позиция робота (";
		error += std::to_string(pos.x);
		error += ",";
		error += std::to_string(pos.y);
		error += ") направление движения: ";
		switch (dir)
		{
		case Direction::RIGHT:
			error += "вправо";
			break;
		case Direction::LEFT:
			error += "влево";
			break;
		case Direction::DOWN:
			error += "вниз";
			break;
		case Direction::UP:
			error += "вверх";
			break;
		default:
			break;
		}
	};

	const char* what() const noexcept { return error.c_str(); };

private:
	std::string error;
};

class IllegalCommand : public std::exception
{
public:
	IllegalCommand() = default;
};

class Robot
{
public:
	Robot() : currPos{}
	{};

	void move(Direction dir);
	void print();	

private:
	Pos currPos;
};