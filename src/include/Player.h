#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>

class Player
{
private:
    const int _defaultPoints = 30;
    static int _id;

public:
    Player();
    Player(std::string name);
    Player(std::string  name, int points);

    Player& operator=(Player& player);

    void setPoints(int points);

    std::string _name;
    int _points;
};

#endif // PLAYER_H
