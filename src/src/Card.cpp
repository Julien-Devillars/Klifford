#include "../include/Card.h"

Card::Card(Number n, Color c) : _number(n), _color(c) {}

Card::Color Card::getColor() 
{
    return _color;
}
Card::Number Card::getNumber()
{
    return _number;
}

std::string Card::getColorName() {
    std::string myColors[] = {"H", "C", "D", "S"};

    return myColors[_color];
}

std::string Card::getNumberName() {
    std::string myNumber[] = {"Joker", "As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    return myNumber[_number];
}


std::string Card::DrawCard() {
    return getNumberName() + " " + getColorName();
}

Card& Card::operator=(const Card& card)
{
    this->_color = card._color;
    this->_number = card._number;

    return *this;
};

bool operator==(const Card& card1, const Card& card2)
{
    return card1._color == card2._color && card1._number == card2._number;
};

bool operator!=(const Card& card1, const Card& card2)
{
    return !(card1 == card2);
};
