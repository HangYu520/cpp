#pragma once
#include <iostream>
#include "Entity.h"
#define LOG(x) std::cout << x << std::endl

class Player : public Entity
{
public:
    const char* Name; // 指向的内容不可修改，指针本身可以修改

public:
    Player(int x, int y, const char* name);
   
    ~Player();
    
    void log();
};