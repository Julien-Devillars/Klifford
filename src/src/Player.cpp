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
void Player::setPoints(int points)
{
    this->_points = points;
}
