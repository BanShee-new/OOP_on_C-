#include"Task4.h"

Denomination operator++(Denomination& den) { return den = (Denomination)(std::underlying_type<Denomination>::type(den) + 1); };
Denomination operator*(Denomination den) { return den; };
Denomination begin(Denomination den) { return Denomination::first; };
Denomination end(Denomination den) 
{
	Denomination de = Denomination::last;
	return ++de; 
};

Suit operator++(Suit& suit) { return suit = (Suit)(std::underlying_type<Suit>::type(suit) + 1); };
Suit operator*(Suit suit) { return suit; };
Suit begin(Suit suit) { return Suit::first; };
Suit end(Suit suit)
{
	Suit su = Suit::last;
	return ++su; 
};


Card::Card() : isHidden{ true }, isStayedInTheDeck{ true }
{};

void Card::setValue(Denomination den, Suit suit)
{
	denomination = den;
	this->suit = suit;
}
uint16_t Card::getValue()
{
	uint16_t val = std::underlying_type<Denomination>::type(denomination);
	if (val > 10) val = 10;
	return val;
}
;

Deck::Deck()
{
	for (const auto& i : Suit())
	{
		for (const auto& j : Denomination())
		{
			cards[(int)i - 1][(int)j - 1].setValue(j, i);
		}
	}	
}
