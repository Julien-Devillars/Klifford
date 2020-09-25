#include "gtest/gtest.h"
#include "../src/include/Deck.h"

#include <deque>

class deckTest : public ::testing::Test
{
protected:
	friend Deck;
	Deck deck;

	virtual void SetUp() override
	{
		deck = Deck();
	};
	//virtual void TearDown() override {};

};

TEST_F(deckTest, testInitFunctions)
{
	deck.init4();
	EXPECT_EQ(deck.getNbCards(), 4);
	EXPECT_EQ(deck.getCards().size(), 4);
	EXPECT_EQ(deck.getPositionCard(), 0);

	deck.init32();
	EXPECT_EQ(deck.getNbCards(), 32);
	EXPECT_EQ(deck.getCards().size(), 32);
	EXPECT_EQ(deck.getPositionCard(), 0);

	deck.init52();
	EXPECT_EQ(deck.getNbCards(), 52);
	EXPECT_EQ(deck.getCards().size(), 52);
	EXPECT_EQ(deck.getPositionCard(), 0);
}

TEST_F(deckTest, testOperatorAssignement)
{
	Deck d1 = Deck();
	d1.init32();
	Deck d2 = d1;

	EXPECT_EQ(d1.getCards(), d2.getCards());
	EXPECT_EQ(d1.getNbCards(), d2.getNbCards());
	EXPECT_EQ(d1.getPlacement(), d2.getPlacement());
	EXPECT_EQ(d1.getPositionCard(), d2.getPositionCard());
}

TEST_F(deckTest, testOperatorEquality)
{
	Deck d1 = Deck();
	d1.init32();
	Deck d2 = Deck();
	d2.init32();

	EXPECT_EQ(d1, d2);
}

TEST_F(deckTest, testShuffle)
{
	Deck d1 = Deck();
	d1.init52();
	Deck d2 = d1;
	int N = 500;
	d1.shuffle(N); // 500 permutations 

	EXPECT_NE(d1, d2);
}

TEST_F(deckTest, testFetchCard)
{
	deck.init4();

	for (int i = 0; i < 4; ++i)
	{
		EXPECT_EQ(deck.getPositionCard(), i);
		EXPECT_EQ(deck.fetchCard(), Card(Card::As, static_cast<Card::Color>(i)));
	}
}

TEST_F(deckTest, testputBackCards)
{
	deck.init4();	// Replace the 4 as with the 4 cards below
	std::deque<Card> cards{ KingC, JackC, NineH, NineD };

	deck.putBackCards(cards);
	EXPECT_EQ(deck.getPlacement(), 4);

	for (int i = 0; i < deck.getCards().size(); ++i)
		EXPECT_EQ(deck.getCards()[i], cards[i]);
}