#include<iostream>
#include"Task3-4-5.h"

Rank operator++(Rank& den) { return den = (Rank)(std::underlying_type<Rank>::type(den) + 1); };
Rank operator*(Rank den) { return den; };
Rank begin(Rank den) { return Rank::first; };
Rank end(Rank den) 
{
	Rank de = Rank::last;
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


Card::Card(Rank r, Suit s, bool ifu) : suit(s), rank(r), isFaceUp(ifu)//, isStayedInTheDeck{ true }
{};

void Card::SetValue(Rank den, Suit suit)
{
	rank = den;
	this->suit = suit;
};

uint16_t Card::GetValue() const
{
	uint16_t val = 0;
	if (isFaceUp)
	{
		val = std::underlying_type<Rank>::type(rank);
		if (val > 10) val = 10;
	}
	return val;
};

Deck::Deck()
{
	cards.reserve(52);
	Populate();
}

void Deck::Populate()
{
	Clear();
	for (const auto& s : Suit())
	{
		for (const auto& r : Rank())
		{
			Add(new Card(r, s));
		}
	}
}

void Deck::Shuffle()
{
	std::random_shuffle(cards.begin(), cards.end());
}

void Deck::Deal(Hand& aHand)
{
	if (!cards.empty())
	{
		aHand.Add(cards.back());
		cards.pop_back();
	}
	else
	{
		std::cout << "Нет карт. Невозможно дать карту.";
	}
}

void Deck::AdditionalCards(GenericPlayer& aGenerlcPlayer)
{
	std::cout << std::endl;
	while (!aGenerlcPlayer.IsBoosted() && aGenerlcPlayer.IsHitting())
	{
		Deal(aGenerlcPlayer);
		std::cout << aGenerlcPlayer << std::endl;

		if (aGenerlcPlayer.IsBoosted())
		{
			aGenerlcPlayer.Bust();
		}
	}
}

Game::Game(const std::vector<std::string>& names)
{
	for (auto& name : names)
	{
		players.push_back(Player(name));
	}

	std::srand(static_cast<uint32_t>(time(0)));
	deck.Populate();
	deck.Shuffle();
}

void Game::Play()
{
	// раздает каждому по две стартовые карты
	for (size_t i = 0; i < 2; i++)
	{
		for (auto& player : players)
		{
			deck.Deal(player);
		}
		deck.Deal(house);
	}

	// прячет первую карту дилера
	house.FlipFirstCard();

	// открывает руки всех игроков
	for (auto& player : players)
	{
		std::cout << player << std::endl;
	}
	std::cout << house << std::endl;

	// раздает игрокам дополнительные карты
	for (auto& player : players)
	{
		deck.AdditionalCards(player);
	}

	// показывает первую карту дилера
	house.FlipFirstCard();
	std::cout << std::endl << house;

	// раздает дилеру дополнительные карты
	deck.AdditionalCards(house);

	if (house.IsBoosted())
	{
		// все, кто остался в игре, побеждают
		for (auto& player : players)
		{
			if (!player.IsBoosted())
			{
				player.Win();
			}
		}
	}
	else
	{
		// сравнивает суммы очков всех оставшихся игроков с суммой очков дилера
		for (auto& player : players)
		{
			if (!player.IsBoosted())
			{
				if (player.GetTotal() > house.GetTotal())
				{
					player.Win();
				}
				else if (player.GetTotal() < house.GetTotal())
				{
					player.Lose();
				}
				else
				{
					player.Push();
				}
			}
		}
	}

	// очищает руки всех игроков
	for (auto& player : players)
	{
		player.Clear();
	}
	house.Clear();
}

Hand::Hand()
{
	cards.reserve(7);
}

Hand::~Hand()
{
	Clear();
}

void Hand::Add(Card* pCard)
{
	cards.push_back(pCard);
}

void Hand::Clear()
{
	for (auto& cr : cards)
	{
		delete cr;
	}
	cards.clear();
}

uint16_t Hand::GetTotal() const
{
	// если карт в руке нет, возвращает значение 0
	if (cards.empty())
	{
		return 0;
	}
	//если первая карта имеет значение 0, то она лежит рубашкой вверх:
	// вернуть значение 0
	if (cards[0]->GetValue() == 0)
	{
		return 0;
	}
	// находит сумму очков всех карт, каждый туз дает 1 очко
	uint16_t total = 0;
	for (const auto& cr : cards)
	{
		total += cr->GetValue();
	}
	// определяет, держит ли рука туз
	bool containsAce = false;
	for (const auto& cr : cards)
	{
		if (cr->GetValue() == static_cast<uint16_t>(Rank::ACE)) containsAce = true;
	}
	// если рука держит туз и сумма довольно маленькая, туз дает 11 очков
	if (containsAce && total <= 11)
	{
		// добавляем только 10 очков, поскольку мы уже добавили
		// за каждый туз по одному очку
		total += 10;
	}
	return total;
}

GenericPlayer::GenericPlayer(const std::string& name) : name(name)
{}

bool GenericPlayer::IsBoosted() const
{
	return (GetTotal() > 21);
}
void GenericPlayer::Bust() const
{
	std::cout << name << " перебор" << std::endl;
}

House::House(const std::string& name) : GenericPlayer(name)
{}

bool House::IsHitting() const
{
	return (GetTotal() <= 16);
}

void House::FlipFirstCard()
{
	if (!(cards.empty()))
	{
		cards[0]->Flip();
	}
	else
	{
		std::cout << "Нет карт для переворота!\n";
	}
}

std::ostream& operator<<(std::ostream& os, const Card& aCard)
{
	const std::string RANKS[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
	// { "♣️", "♦️", "♥️", "♠️" };
	const char SUITS[] = { 5, 4, 3, 6 };
	if (aCard.isFaceUp)
	{
		os << RANKS[static_cast<uint16_t>(aCard.rank) - 1] << SUITS[static_cast<uint16_t>(aCard.suit) - 1];
	}
	else
	{
		os << "XX";
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer)
{
	os << aGenericPlayer.name << ":\t";
	if (!aGenericPlayer.cards.empty())
	{
		if (aGenericPlayer.GetTotal() != 0)
		{
			std::cout << "(" << aGenericPlayer.GetTotal() << ")\t";
		}
		for (const auto& pCard : aGenericPlayer.cards)
		{
			os << *pCard << "\t";
		}
		
	}
	else
	{
		os << "<empty>";
	}
	return os;
}

Player::Player(const std::string& name) : GenericPlayer(name)
{}

bool Player::IsHitting() const
{
	std::cout << name << ", нужна еще карта? (Y/N): ";
	char response;
	std::cin >> response;
	return (response == 'y' || response == 'Y');
}

void Player::Win() const
{
	std::cout << name << " выиграл." << std::endl;
}

void Player::Lose() const
{
	std::cout << name << " проиграл." << std::endl;
}

void Player::Push() const
{
	std::cout << name << " сыграл вничью." << std::endl;
}