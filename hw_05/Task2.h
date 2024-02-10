#pragma once

template<typename T1, typename T2>
class Pair
{
public:
	Pair(const T1& f, const T2& s) : fr(f), sc(s)
	{};

	T1 first() const { return fr; };
	T2 second() const { return sc; };

private:
	T1 fr;
	T2 sc;
};