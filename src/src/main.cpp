#include <iostream>
#include "../include/Card.h"
#include "../include/Deck.h"



int main(int argc, char* argv[])
{
    srand(time(NULL));

    Deck d;
    d.init4();
    d.shuffle();
    d.DrawDeck();
    std::cout << "----------------" << std::endl;


    return 1;
}
