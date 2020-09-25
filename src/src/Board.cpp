#include "../include/Board.h"
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
    _deck.shuffle(_PERMUTATION);
    _NB_PLAYERS = 1;
    _players.push_back(Player("Admin"));

    _board = std::vector<Case>(_NB_CARDS_ON_BOARD);

    for (int i = 0; i < _NB_CARDS_ON_BOARD; ++i)
        _board[i].addHigher(_deck.fetchCard());

    updateHigherPile();
}

Board::Board(std::vector<Player>& players)
{
    _deck.init32();
    _deck.shuffle(_PERMUTATION);
    _NB_PLAYERS = players.size();
    _players = players;

    _board = std::vector<Case>(_NB_CARDS_ON_BOARD);

    for (int i = 0; i < _NB_CARDS_ON_BOARD; ++i)
        _board[i].addHigher(_deck.fetchCard());

    updateHigherPile();
}

void Board::win(int idxCase, bool HigherOrLower, Card c)
{
    printf("Next card is : %s\n", c.DrawCard().c_str());
    HigherOrLower ? _board[idxCase].addHigher(c) : _board[idxCase].addLower(c);
    _NB_PLAYS++;

    updateHigherPile();
}

void Board::checkRemovePlayer()
{
    for(int i = 0 ; i < _NB_PLAYERS ; i++)
    {
        if (_players[i]._points <= 0)
        {
            auto ite = _players.begin() + i;
            _players.erase(ite);
            _NB_PLAYERS--;
            i--;
        }
    }
   
}

void Board::lose(int idxCase, bool HigherOrLower, Card c)
{
    printf("\nNext card is : %s\n", c.DrawCard().c_str());
    
    HigherOrLower ? _board[idxCase].addHigher(c) : _board[idxCase].addLower(c);

    _players[_idxCurrentPlayer].removePoints(_board[idxCase]._NBCARDS);

    checkRemovePlayer();

    printf("You loose %d points.\n", _board[idxCase]._NBCARDS);

    _deck.putBackCards(_board[idxCase]._cards);

    _board[idxCase].clear();
    _board[idxCase].addHigher(_deck.fetchCard());

    _NB_PLAYS = 0;

    updateHigherPile();
}

bool Board::winCondition()
{
    // 2 ways to win the game
    

    // There is only one player left (all players lost all their points)
    if (_players.size() == 1) {
        printf("Player %s won the game, no more player left", _players[_idxCurrentPlayer]._name.c_str());
        return true;
    }

    // There is no more cards
    int cpt = 0;
    for (auto& c : _board)
        cpt += c._NBCARDS;

    if (cpt == _deck.getNbCards())
    {
        printf("Player %s won the game, no more cards left", _players[_idxCurrentPlayer]._name.c_str());
        return true;
    }

    return false;
}

void Board::playOnPile(int idxCase, int GreaterOrLess, bool HigherOrLower)
{
    // GreaterOrLess =>  -1 : Less | 0 = Equal | 1 = Greater
    // HigherOrLOwer =>   0 : Play on the highest card | 1 : Play on the lowest card

    Card nextCard = _deck.fetchCard();
    Card cardChoosen = HigherOrLower  ? *(_board[idxCase]._cards.end()-1) : *_board[idxCase]._cards.begin();


    if (GreaterOrLess == -1)        // Less

        if (nextCard.getNumber() < cardChoosen.getNumber())
            win(idxCase, HigherOrLower, nextCard);
        else
            lose(idxCase, HigherOrLower, nextCard);

    else if (GreaterOrLess == 0)    // Equal

        if (nextCard.getNumber() == cardChoosen.getNumber()) {
            win(idxCase, HigherOrLower, nextCard);
            printf("EQUALITY ! Everyone lose %d points except %s\n", _counterHighestPile, _players[_idxCurrentPlayer]._name.c_str());
            for (int i = 0; i < _NB_PLAYERS; ++i)
                if (i != _idxCurrentPlayer)
                    _players[i].removePoints(_counterHighestPile);
            checkRemovePlayer();
        }
        else
            lose(idxCase, HigherOrLower, nextCard);

    else                            // Greater
        if (nextCard.getNumber() > cardChoosen.getNumber())
            win(idxCase, HigherOrLower, nextCard);
        else
            lose(idxCase, HigherOrLower, nextCard);

}

void Board::printCard(int idxCase, bool HigherOrLower)
{
    printf("\nCard : %s\n", HigherOrLower ?
        _board[idxCase]._cards[_board[idxCase]._cards.size()-1].DrawCard().c_str()
        : _board[idxCase]._cards[0].DrawCard().c_str()
    );
}

void Board::play() 
{
    bool replay;
    do
    {
        drawBoard();
        int idxCase;
        bool newPlayer = false;
        if (_NB_PLAYS == 0)
        {
            do {
                printf("\nYou must play on the highest pile(s) (choose) : ");
                scanf("%d", &idxCase);

            } while (std::find(_highestPile.begin(), _highestPile.end(), idxCase) == _highestPile.end());
            printf("You choose %d\n", idxCase);
        }
        else
        {
            bool stillPlaying = true;
            if (_NB_PLAYS > _NB_PLAY_BEFORE_NEXT)
            {
                printf("Do you wanna continue ? (no : 0 / YES : 1) : \n");
                scanf("%d", &stillPlaying);
            }
            if (stillPlaying)
            {
                printf("Quel case jouer ? (0- %d) : ", _NB_CARDS_ON_BOARD - 1);
                scanf("%d", &idxCase);
            }
            else
            {
                nextPlayer();
                newPlayer = true;
            }
        }

        if (!newPlayer)
        {
            int GreaterOrLess;
            int HigherOrLower;  // bool

            printf("You have to choose which card play : Higher (0) or Lower (1) one : ");
            scanf("%d", &HigherOrLower);


            printCard(idxCase, static_cast<bool>(HigherOrLower));

            printf("You have to choose less (-1) or equal (0) or greater (1) : ");
            scanf("%d", &GreaterOrLess);

            playOnPile(idxCase, GreaterOrLess, static_cast<bool>(HigherOrLower));
        }

        
    } while (!winCondition());
}

void Board::nextPlayer()
{
    _idxCurrentPlayer = (_idxCurrentPlayer + 1 ) % _NB_PLAYERS;
    _NB_PLAYS = 0;
}


void Board::drawBoard()
{
    system("CLS"); // Clear the console
    printf("\n\n");
    
    printf("\n\nPlayer : %s\n", _players[_idxCurrentPlayer]._name.c_str());
    printf("Points : %d\n", _players[_idxCurrentPlayer]._points);
    printf("Nb Plays: %d\n", _NB_PLAYS);
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

    for (int i = 0; i < _NB_CARDS_ON_BOARD; ++i)
        if (_counterHighestPile == _board[i]._NBCARDS)
            _highestPile.push_back(i);

}

