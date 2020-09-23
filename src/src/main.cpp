#include <iostream>
#include "../include/Card.h"

int main(int argc, char* argv[])
{
	Card myCard(Card::Number::Height, Card::Color::Diamond);

	std::cout << myCard.DrawCarte() << std::endl;


	return 1;
}
