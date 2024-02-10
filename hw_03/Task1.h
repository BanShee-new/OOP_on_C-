#pragma once
#include<cstdint>

namespace figures
{
	class Figure
	{
	public:

		virtual float area() = 0;
		void printArea();

		virtual ~Figure() {};
	};

	class Parallelogram : public Figure
	{
	public:
		Parallelogram(uint16_t a, uint16_t h) : a{ a }, h{ h }
		{};

		float area() override;

	protected:
		uint16_t a, h;
	};

	class Circle : public Figure
	{
	public:
		Circle(uint16_t r) : r{ r }
		{};

		float area() override;

	private:
		uint16_t r;
	};

	class Rectangle : public Parallelogram
	{
	public:
		Rectangle(uint16_t a, uint16_t b) : Parallelogram(a, b)
		{};
	};

	class Square : public Parallelogram
	{
	public:
		Square(uint16_t a) : Parallelogram(a, a)
		{};
	};

	class Rhombus : public Parallelogram
	{
	public:
		Rhombus(uint16_t d1, uint16_t d2) : Parallelogram(d1, d2)
		{};

		float area() override;
	};
}