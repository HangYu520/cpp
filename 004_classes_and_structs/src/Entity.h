#pragma once
#include <iostream>

class Entity {
public:
    int X, Y;

public:
    Entity();
    
    ~Entity();
    
    void move(int xa, int ya);
};