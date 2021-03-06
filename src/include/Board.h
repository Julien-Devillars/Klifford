#ifndef __BOARD_H__
#define __BOARD_H__

#include "Deck.h"
#include "Player.h"

#include <istream>
#include <stdlib.h>

#include <vector>
#include <deque>

class Case
{
public:
    Case();

    int _NBCARDS;
    std::deque<Card> _cards;
    void addHigher(Card c);
    void addLower(Card c);
    void clear();
    void drawCase();
};


class Board
{
public:
    int _NB_PLAY_BEFORE_NEXT = 1;
    int _NB_CARDS_ON_BOARD = 5;
    const int _PERMUTATION = 1'000;
    Deck _deck;
    std::vector<Case> _board;
    int _counterHighestPile = 1;
    std::vector<int> _highestPile;

    int _NB_PLAYERS = 0;
    int _NB_PLAYS = 0;

    std::vector<Player> _players;
    int _idxCurrentPlayer = 0;

    Board();
    Board(std::vector<Player>& players);

    void updateHigherPile();
    void drawBoard();
    void win(int idxCase, bool HigherOrLower, Card c);
    void lose(int idxCase, bool HigherOrLower, Card c);
    void playOnPile(int idxCase, int GreaterOrLess, bool HigherOrLower);
    bool winCondition();
    void printCard(int idxCase, bool GreaterOrLess);
    void play();
    void checkRemovePlayer();
    void nextPlayer();
};
#endif // BOARD_H
