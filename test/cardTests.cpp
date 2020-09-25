#include "gtest/gtest.h"
#include "../src/include/Card.h"

#include <string>

class cardTest : public ::testing::Test
{
protected:

	std::string myColors[Card::NB_COLOR] = { "H", "C", "D", "S" };
	std::string myNumbers[Card::NB_NUMBER] = { "Joker", "As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

	Card card;

	virtual void SetUp() override
	{
		card = Card();
	};
	//virtual void TearDown() override {};

};


TEST_F(cardTest, testColors)
{
	for (int i = 0; i < Card::NB_COLOR; ++i)
	{
		card = Card(Card::As, static_cast<Card::Color>(i));
		ASSERT_EQ(myColors[i], card.getColorName());
	}
}

TEST_F(cardTest, testNumbers)
{
	for (int i = 0; i < Card::NB_NUMBER; ++i)
	{
		card = Card(static_cast<Card::Number>(i), Card::Heart);
		ASSERT_EQ(myNumbers[i], card.getNumberName());
	}
}

TEST_F(cardTest, testDrawCard)
{
	for (int i = 0; i < Card::NB_NUMBER; ++i)
	{
		for (int j = 0; j < Card::NB_COLOR; ++j)
		{
			card = Card(static_cast<Card::Number>(i), static_cast<Card::Color>(j));
			ASSERT_EQ(myNumbers[i] + " " + myColors[j], card.DrawCard());
		}
	}
}

TEST_F(cardTest, testOperatorAssignement)
{
	Card c1 = Card(Card::As, Card::Heart); // As Heart
	Card c2 = c1;

	EXPECT_EQ(c1.getColor(), c2.getColor());
	EXPECT_EQ(c1.getColorName(), c2.getColorName());
	EXPECT_EQ(c1.getNumber(), c2.getNumber());
	EXPECT_EQ(c1.getNumberName(), c2.getNumberName());
}

TEST_F(cardTest, testOperatorEquality)
{
	Card c1 = Card(Card::As, Card::Heart); // As Heart
	Card c2 = Card(Card::As, Card::Heart); // As Heart

	EXPECT_EQ(c1, c2);
}

