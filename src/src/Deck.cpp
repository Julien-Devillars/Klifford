#include "../include/Deck.h"

Deck::Deck(){};

void Deck::init32()
{
    _NBCARDS = 32;
    _cards.clear();
    for(int i = 0; i < Card::Color::NB_COLOR ; ++i)
        for(int j = 1 ; j < Card::Number::NB_NUMBER; j = (j==1) ? 7 : ++j)
            _cards.push_back(Card(static_cast<Card::Number>(j), static_cast<Card::Color>(i)));
};

void Deck::init52()
{
    _NBCARDS = 52;
    _cards.clear();
    for(int i = 0; i < Card::Color::NB_COLOR ; ++i)
        for(int j = 1 ; j < Card::Number::NB_NUMBER; j = ++j)
            _cards.push_back(Card(static_cast<Card::Number>(j), static_cast<Card::Color>(i)));
};


void Deck::init4()
{
    _NBCARDS = 4;
    _cards.clear();
    for(int i = 0; i < Card::Color::NB_COLOR ; ++i)
        _cards.push_back(Card(Card::As, static_cast<Card::Color>(i)));
};

void Deck::shuffle()
{
    const int NB_PERMUTATION = 500;

    for(int i = 0 ; i < NB_PERMUTATION ; ++i)
        std::swap(_cards[rand()%_NBCARDS], _cards[rand()%_NBCARDS]);

};

void Deck::DrawDeck()
{
    for(auto& card : _cards)
        printf("%s\n",card.DrawCard().c_str());
};

Card Deck::FetchCard()
{
    return _cards[(_positionCard > _NBCARDS-1) ? _positionCard = 0 : _positionCard++];
};

void Deck::putBackCard(std::vector<Card> c)
{

    for (int i = 0; i < c.size(); ++i)
    {
        _cards[(_placement > _NBCARDS-1) ? _placement = 0 : _placement++] = c[i];
    }
};













