#ifndef __CARD_H__
#define __CARD_H__

#include <string>


class Card {

public:
    enum Color { Heart, Club, Diamond, Spade, NB_COLOR };
    enum Number { Joker, As, Two, Three, Four, Five, Six, Seven, Height, Nine, Ten, Jack, Queen, King, NB_NUMBER };

    Card(Number n, Color c);
    
    std::string DrawCarte();

private:
    Color _color;
    Number _number;

    std::string getColor();
    std::string getNumber();


};

#endif