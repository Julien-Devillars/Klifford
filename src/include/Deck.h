#ifndef __DECK_H__
#define __DECK_H__

#include "Card.h"

#include <string>
#include <vector>

#include <stdlib.h> // srand, rand
#include <time.h>   // time
#include <stdio.h>  // NULL

class Deck {

public:

    Deck();

    void init32();      // Initialize the deck with 32 cards, straight as As, 7, 8, ..., Queen, King
    void init52();      // Initialize the deck with 52 cards, from As to King
    void init4();

    void shuffle();     // Shuffle the deck
    void DrawDeck();    // Print all the deck

    Card FetchCard();                               // Able to take a card
    void putBackCard(std::vector<Card> c);   // If a pile is lost, put back all the pile at the ned of the deck

private:

    std::vector<Card> _cards;
    int _positionCard = 0;
    int _placement = 0;
    int _NBCARDS = 0;

};

#endif // DECK_H
