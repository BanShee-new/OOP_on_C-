#pragma once
#include <type_traits>
#include<string>
//#include<stdint.h>

//<<-----------Колода---------------

enum class Denomination
{
	A = 1,
	_2, _3, _4, _5, _6, _7, _8, _9, _10,
	J, Q, K,
	first = A,
	last = K
};

enum class Suit
{
	clubs = 1,	//♣️
	diamonds,	//♦️
	hearts,		//♥️
	spades,		//♠️
	first = clubs,
	last = spades
};

class Card
{
public:
	Card();
	
	void setValue(Denomination den, Suit suit);
	
	Denomination getDenomination() { return denomination; };
	Suit getSuit() { return suit; };

private:
	Denomination denomination;
	Suit suit;
	bool isStayedInTheDeck;

};

class Deck
{
public:
	Deck();

	Card getCard(uint16_t number);
	bool checkIsStayedCard(uint16_t number);

private:
	uint16_t numberOfCards = (int)Suit::last * (int)Denomination::last;
	Card cards[(int)Suit::last][(int)Denomination::last]{};
};

//-------------Колода------------->>

//<<-----------Фишки, Очки---------------

enum class Chip
{
	White	= 1,
	Red		= 5,
	Blue	= 10,
	Green	= 25,
	Black	= 100,
	Magenta	= 500,
	Orange	= 1000,

	count = 7
};

class ChipsOnHand
{
public:

private:
	Chip chips[(int)Chip::count]{};
};

//-------------Фишки, Очки------------->>

//<<-----------Участники игры---------------

class GameEntity
{
public:

private:
	std::string name;
	//int64_t 
};

//-------------Участники игры------------->>
