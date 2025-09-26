#pragma once
#include <iostream>
#define LOG(x) std::cout << x << std::endl

class Player
{
private:
    int x, y;
    int speed;

public:
    Player(int xa, int ya, int speeda);
    ~Player(){};
    
    void move(int xa, int ya);
    
    void log();
};