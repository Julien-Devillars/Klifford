#include "gtest/gtest.h"
#include "../src/include/Board.h"

#include <vector>

class caseTest : public ::testing::Test
{
protected:
	Case myCase;

	virtual void SetUp() override
	{
		myCase = Case();
	};
	//virtual void TearDown() override {};

};

TEST_F(caseTest, testConstructor)
{
	EXPECT_EQ(myCase._NBCARDS, 0);
}
TEST_F(caseTest, testAddHigherAll)
{
	Deck deck;

	deck.init52();
	deck.shuffle(100);

	for (int i = 0; i < deck.getNbCards(); ++i)
	{
		Card c = deck.fetchCard();

		myCase.addHigher(c);

		EXPECT_EQ(myCase._NBCARDS, i + 1);
		EXPECT_EQ(myCase._cards.size(), i + 1);
		EXPECT_EQ(myCase._cards[i], c);
	}
}

TEST_F(caseTest, testAddLowerAll)
{
	Deck deck;

	deck.init52();
	deck.shuffle(100);

	for (int i = 0; i < deck.getNbCards(); ++i)
	{
		Card c = deck.fetchCard();

		myCase.addLower(c);

		EXPECT_EQ(myCase._NBCARDS, i + 1);
		EXPECT_EQ(myCase._cards.size(), i + 1);
		EXPECT_EQ(myCase._cards[0], c);
	}
}

TEST_F(caseTest, testClear)
{
	Deck deck;

	deck.init4();
	deck.shuffle(10);

	for (int i = 0; i < deck.getNbCards(); ++i)
		myCase.addLower(deck.fetchCard());
	
	myCase.clear();
	EXPECT_EQ(myCase._NBCARDS, 0);
	EXPECT_EQ(myCase._cards.size(), 0);
}


class boardTest : public ::testing::Test
{
protected:
	std::vector<Player> players;

	virtual void SetUp() override
	{
		players = std::vector<Player>({ Player("p1"), Player("p2"), Player("p3", 20) });
	};
	//virtual void TearDown() override {};

};

TEST_F(boardTest, testInitDefault)
{
	Board board = Board();

	EXPECT_EQ(board._NB_PLAYERS, 1);
	EXPECT_EQ(board._deck.getNbCards(), 32);
	EXPECT_EQ(board._board.size(), board._NB_CARDS_ON_BOARD);
}

TEST_F(boardTest, testInitWithPlayers)
{
	Board board = Board(players);

	EXPECT_EQ(board._NB_PLAYERS, players.size());
	EXPECT_EQ(board._deck.getNbCards(), 32);
	EXPECT_EQ(board._board.size(), board._NB_CARDS_ON_BOARD);
	EXPECT_EQ(board._players, players);
}

TEST_F(boardTest, testWinPlay)
{
	Board board = Board(players);

	Card asCard = Card(Card::As, Card::Club);

	int idxCase = 0;

	board.win(idxCase, 1, asCard);
	
	EXPECT_EQ(board._highestPile.size(), 1);
	EXPECT_EQ(board._counterHighestPile, 2);
	EXPECT_EQ(board._board[idxCase]._cards.size(), 2);
	EXPECT_EQ(*(board._board[idxCase]._cards.end() - 1), asCard);
	EXPECT_EQ(board._NB_PLAYS, 1);

}

TEST_F(boardTest, testLosePlay)
{
	Board board = Board(players);

	Card asCard = Card(Card::As, Card::Club);

	int idxCase = 0;
	
	int playerPoints = board._players[board._idxCurrentPlayer]._points;
	int pileSize = board._board[idxCase]._NBCARDS + 1;
		
	board.lose(idxCase, 1, asCard);

	EXPECT_EQ(board._highestPile.size(), board._NB_CARDS_ON_BOARD);
	EXPECT_EQ(board._counterHighestPile, 1);
	EXPECT_EQ(board._board[idxCase]._cards.size(), 1);
	EXPECT_EQ(board._NB_PLAYS, 0);
	EXPECT_EQ(board._players[board._idxCurrentPlayer]._points, playerPoints - pileSize);
}

TEST_F(boardTest, testWinCondition)
{
	Board board = Board(players);

	EXPECT_EQ(board.winCondition(), false);
	
	board._players[0].setPoints(0);
	board._players[1].setPoints(0);

	board.checkRemovePlayer();
	
	EXPECT_EQ(board.winCondition(), true);

	Board board2 = Board(players);
	
	EXPECT_EQ(board2.winCondition(), false);

	for (int i = 0; i < board2._deck.getNbCards() - board2._NB_CARDS_ON_BOARD; ++i)
		board2.win(0, true, board2._deck.fetchCard());

	EXPECT_EQ(board2.winCondition(), true);
}