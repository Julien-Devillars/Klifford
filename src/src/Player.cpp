#include "../include/Player.h"

Player::Player() : _name("NoName"), _points(_defaultPoints){};

Player::Player(std::string name) : _name(name), _points(_defaultPoints){};

Player::Player(std::string  name, int points) : _name(name), _points(points){};


Player& Player::operator=(Player& player)
{
    this->_name = player._name;
    this->_points = player._points;

    return *this;
};

bool operator==(const Player& player1, const Player& player2)
{
    return player1._name == player2._name && player1._points == player2._points;
};

void Player::setPoints(int points)
{
    this->_points = points;
}

void Player::removePoints(int points)
{
    this->_points -= points;
}
