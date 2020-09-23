#include "../include/Board.h"
#include <stdlib.h>
Case::Case() : _NBCARDS(0){};

void Case::addHigher(Card c) 
{
    _cards.push_back(c);
    _NBCARDS++;
};
void Case::addLower(Card c) 
{
    _cards.push_front(c);
    _NBCARDS++;
};
void Case::clear() 
{
    _cards.clear();
    _NBCARDS = 0;
};

void Case::drawCase()
{
    for (auto& c : _cards)
        printf("%s\n", c.DrawCard().c_str());
}

Board::Board()
{
    _deck.init32();
    _deck.shuffle();
    _NB_PLAYERS = 1;
    _players.push_back(Player("Admin"));

    _board = std::vector<Case>(_NB_CARDS_ON_BOARD);

    for (int i = 0; i < _NB_CARDS_ON_BOARD; ++i)
        _board[i].addHigher(_deck.FetchCard());

    updateHigherPile();
}


Board::Board(std::vector<Player>& players)
{
    _deck.init32();
    _deck.shuffle();
    _NB_PLAYERS = players.size();
    _players = players;

    _board = std::vector<Case>(_NB_CARDS_ON_BOARD);

    for(int i = 0 ; i < _NB_CARDS_ON_BOARD ; ++i)
        _board[i].addHigher(_deck.FetchCard());
    

    _board[2].addHigher(_deck.FetchCard());
    _board[2].addHigher(_deck.FetchCard());
    _board[2].drawCase();
    
    updateHigherPile();
}

void Board::drawBoard()
{
    system("CLS"); // Clear the console
    printf("\n\nPlayer : %s\n", _players[_idxCurrentPlayer]._name.c_str());
    printf("NB Plays: %d\n", _NB_PLAYS);
    printf("Size Pile : %d\n", _counterHighestPile);

    std::string highestPiles = "";
    for (int i = 0; i < _highestPile.size(); ++i)
        highestPiles += std::to_string(_highestPile[i]) + (i == _highestPile.size() - 1 ? "\n" : " | ");
    printf("Highest Pile(s) : %s\n", highestPiles.c_str());

    for (int i = 0; i < _counterHighestPile; ++i)
    {
        for (int j = 0; j < _NB_CARDS_ON_BOARD; j++)
            if (i < _board[j]._NBCARDS)
                printf("%6s", _board[j]._cards[i].DrawCard().c_str());
            else 
                printf("%6s", "");
            
        printf("\n");
    }


}

void Board::updateHigherPile() {
    _highestPile.clear();

    _counterHighestPile = 0;

    for(auto& myCase : _board)
        _counterHighestPile = std::max(_counterHighestPile, myCase._NBCARDS);
    
    printf("Counter : %d", _counterHighestPile);

    for (int i = 0; i < _NB_CARDS_ON_BOARD; ++i)
        if (_counterHighestPile == _board[i]._NBCARDS)
            _highestPile.push_back(i);

    printf("Highest : %d", _highestPile[0]);
}

