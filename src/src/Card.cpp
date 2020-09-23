#include "../include/Card.h"

Card::Card(Number n, Color c) : _number(n), _color(c) {}

std::string Card::getColor() {
    std::string myColors[] = {"H", "C", "D", "S"};

    return myColors[_color];
}

std::string Card::getNumber() {
    std::string myNumber[] = {"Joker", "As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    return myNumber[_number];
}


std::string Card::DrawCard() {
    return getNumber() + " " + getColor();
}
