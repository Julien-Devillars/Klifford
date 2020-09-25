#include "gtest/gtest.h"
#include "../src/include/Player.h"

class playerTest : public ::testing::Test
{
protected:
	Player p1;
	Player p2;

	virtual void SetUp() override 
	{
		p1 = Player("p1");
		p2 = Player("p2", 20);
	};
	//virtual void TearDown() override {};
	
};


TEST_F(playerTest, testNameAndPoints)
{
	EXPECT_EQ(p1._name, "p1");

	EXPECT_EQ(p2._name, "p2");
	EXPECT_EQ(p2._points, 20);
}

TEST_F(playerTest, testSetPoints)
{
	p1.setPoints(0);
	EXPECT_EQ(p1._points, 0);

	p1.setPoints(10);
	EXPECT_EQ(p1._points, 10);

	p1.setPoints(p2._points);
	EXPECT_EQ(p1._points, p2._points);
}

TEST_F(playerTest, testRemovePoints)
{
	int myPoints = 100, myRemovePoints = 5;

	p1.setPoints(myPoints);
	p1.removePoints(myRemovePoints);
	EXPECT_EQ(p1._points, myPoints - myRemovePoints);

	p1.setPoints(myPoints);
	p2.setPoints(myPoints);
	p1.removePoints(myRemovePoints);
	EXPECT_NE(p1._points, p2._points);
}

TEST_F(playerTest, testAssignement)
{
	p1 = p2;
	EXPECT_EQ(p1._name, p2._name);
	EXPECT_EQ(p1._points, p2._points);

}

TEST_F(playerTest, testEquality)
{
	p1 = p2;
	EXPECT_EQ(p1, p2);

}
