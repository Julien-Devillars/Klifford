#include "gtest/gtest.h"
#include "../src/include/Board.h"

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
	Board board;

	virtual void SetUp() override
	{
		//board = Board();
	};
	//virtual void TearDown() override {};

};