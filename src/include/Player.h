#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>

class Player
{
private:
    const int _defaultPoints = 10;
    static int _id;

public:
    Player();
    Player(std::string name);
    Player(std::string  name, int points);

    Player& operator=(Player& player);
    bool operator==(const Player& player);

    void setPoints(int points);
    void removePoints(int points);

    std::string _name;
    int _points;
};

#endif // PLAYER_H
