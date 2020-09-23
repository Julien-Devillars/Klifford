#ifndef __BOARD_H__
#define __BOARD_H__

#include "Deck.h"
#include "Player.h"

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
    int _NB_PLAY_BEFORE_NEXT = 2;
    int _NB_CARDS_ON_BOARD = 5;

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
    void Win(int indexCase, bool borne, Card c);
    void Lose(int indexCase, bool borne, Card c);
    void play(int indexCase, int choix, bool borne);
    void nextPlayer();
};
#endif // BOARD_H
