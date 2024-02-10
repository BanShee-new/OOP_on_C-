#pragma once

template<typename T>
class Pair1
{
public:
	Pair1(const T& f, const T& s) : fr(f), sc(s)
	{};

	T first() const { return fr; };
	T second() const { return sc; };

private:
	T fr, sc;
};