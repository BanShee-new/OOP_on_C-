#include"Task1.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include<iostream>

using namespace figures;

float Parallelogram::area()
{
	return static_cast<float>(a) * h;
}

void Figure::printArea()
{
	std::cout << "Площадь S = " << area() << std::endl;
}

float Circle::area()
{
	return M_PI * powl(r, 2);
}

float Rhombus::area()
{
	return static_cast<float>(a)*h/2;
}