#include <iostream>
#include "../include/Card.h"
#include "../include/Deck.h"
#include "../include/Board.h"
#include "../include/Player.h"


int main(int argc, char* argv[])
{
    srand(time(NULL));

    Deck d;
    d.init4();
    d.shuffle();
    d.DrawDeck();
    std::cout << "----------------" << std::endl;

    Player Ju("Ju");
    Player Tim("Tim");
    Player Raph("Raph");

    std::vector<Player> players{Ju, Tim, Raph};
    Board b(players);
    b.drawBoard();



    return 1;
}
