#include "Player.h"

Player::Player(int xa, int ya, int speeda)
{
    x = xa;
    y = ya;
    speed = speeda;
}

void Player::move(int xa, int ya)
{
    x += xa * speed;
    y += ya * speed;
}

void Player::log()
{
    LOG("Player: " << x << ", " << y);
}