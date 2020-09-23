#ifndef __CARD_H__
#define __CARD_H__

#include <string>

class Card {

public:
    enum Color { Heart, Club, Diamond, Spade, NB_COLOR };
    enum Number { Joker, As, Two, Three, Four, Five, Six, Seven, Height, Nine, Ten, Jack, Queen, King, NB_NUMBER };

    Card(Number n, Color c);
    Card(){};
    
    std::string DrawCard();

    Color getColor();
    Number getNumber();

private:
    Color _color;
    Number _number;

    std::string getColorName();
    std::string getNumberName();

};

static const Card AsH = Card(Card::As, Card::Heart);
static const Card AsC = Card(Card::As, Card::Club);
static const Card AsD = Card(Card::As, Card::Diamond);
static const Card AsS = Card(Card::As, Card::Spade);

static const Card TwoH = Card(Card::Two, Card::Heart);
static const Card TwoC = Card(Card::Two, Card::Club);
static const Card TwoD = Card(Card::Two, Card::Diamond);
static const Card TwoS = Card(Card::Two, Card::Spade);

static const Card ThreeH = Card(Card::Three, Card::Heart);
static const Card ThreeC = Card(Card::Three, Card::Club);
static const Card ThreeD = Card(Card::Three, Card::Diamond);
static const Card ThreeS = Card(Card::Three, Card::Spade);

static const Card FourH = Card(Card::Four, Card::Heart);
static const Card FourC = Card(Card::Four, Card::Club);
static const Card FourD = Card(Card::Four, Card::Diamond);
static const Card FourS = Card(Card::Four, Card::Spade);

static const Card FiveH = Card(Card::Five, Card::Heart);
static const Card FiveC = Card(Card::Five, Card::Club);
static const Card FiveD = Card(Card::Five, Card::Diamond);
static const Card FiveS = Card(Card::Five, Card::Spade);

static const Card SixH = Card(Card::Six, Card::Heart);
static const Card SixC = Card(Card::Six, Card::Club);
static const Card SixD = Card(Card::Six, Card::Diamond);
static const Card SixS = Card(Card::Six, Card::Spade);

static const Card SevenH = Card(Card::Seven, Card::Heart);
static const Card SevenC = Card(Card::Seven, Card::Club);
static const Card SevenD = Card(Card::Seven, Card::Diamond);
static const Card SevenS = Card(Card::Seven, Card::Spade);

static const Card HeightH = Card(Card::Height, Card::Heart);
static const Card HeightC = Card(Card::Height, Card::Club);
static const Card HeightD = Card(Card::Height, Card::Diamond);
static const Card HeightS = Card(Card::Height, Card::Spade);

static const Card NineH = Card(Card::Nine, Card::Heart);
static const Card NineC = Card(Card::Nine, Card::Club);
static const Card NineD = Card(Card::Nine, Card::Diamond);
static const Card NineS = Card(Card::Nine, Card::Spade);

static const Card TenH = Card(Card::Ten, Card::Heart);
static const Card TenC = Card(Card::Ten, Card::Club);
static const Card TenD = Card(Card::Ten, Card::Diamond);
static const Card TenS = Card(Card::Ten, Card::Spade);

static const Card JackH = Card(Card::Jack, Card::Heart);
static const Card JackC = Card(Card::Jack, Card::Club);
static const Card JackD = Card(Card::Jack, Card::Diamond);
static const Card JackS = Card(Card::Jack, Card::Spade);

static const Card QueenH = Card(Card::Queen, Card::Heart);
static const Card QueenC = Card(Card::Queen, Card::Club);
static const Card QueenD = Card(Card::Queen, Card::Diamond);
static const Card QueenS = Card(Card::Queen, Card::Spade);

static const Card KingH = Card(Card::King, Card::Heart);
static const Card KingC = Card(Card::King, Card::Club);
static const Card KingD = Card(Card::King, Card::Diamond);
static const Card KingS = Card(Card::King, Card::Spade);

#endif // CARD_H
