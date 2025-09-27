#include "Player.h"

Player::Player(int x, int y, const char* name)
{
    X = x;
    Y = y;
    Name = name;
    std::cout << "Created player !" << std::endl;
}

Player::~Player()
{
    std::cout << "Destroyed player !" << std::endl;
}

void Player::log()
{
    LOG("Player " << Name << " is at (" << X << ", " << Y << ")");
}