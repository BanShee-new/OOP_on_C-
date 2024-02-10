#pragma once
#include "Task2.h"

template <typename T>
class StringValuePair : public Pair<std::string, T>
{
public:
	StringValuePair(const std::string& str, const T& sc) : Pair<std::string, T>(str, sc)
	{};
};