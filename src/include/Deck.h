#ifndef __DECK_H__
#define __DECK_H__

#include "Card.h"

#include <string>
#include <vector>
#include <deque>

#include <stdlib.h> // srand, rand
#include <time.h>   // time
#include <stdio.h>  // NULL

class Deck {

public:

    Deck();

    void init32();      // Initialize the deck with 32 cards, straight as As, 7, 8, ..., Queen, King
    void init52();      // Initialize the deck with 52 cards, from As to King
    void init4();       // Initialize the deck with 04 cards, only As, (mainly for test)

    void shuffle(int permutation);     // Shuffle the deck
    void DrawDeck();    // Print all the deck

    Card fetchCard();                               // Able to take a card
    void putBackCards(std::deque<Card> c);           // If a pile is lost, put back all the pile at the ned of the deck

    int getNbCards();
    int getPositionCard();
    int getPlacement();
    std::vector<Card> getCards();

    Deck& operator=(const Deck& deck);
    friend bool operator==(const Deck& deck1, const Deck& deck2);
    friend bool operator!=(const Deck& deck1, const Deck& deck2);
private:
    
    std::vector<Card> _cards;
    int _positionCard = 0;
    int _placement = 0;
    int _NBCARDS = 0;

};

#endif // DECK_H
