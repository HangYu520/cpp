#include "Entity.h"

Entity::Entity()
{
    X = Y = 0;
    std::cout << "Created Entity !" << std::endl;
}

Entity::~Entity()
{
    std::cout << "Destroyed Entity !" << std::endl;
}

void Entity::move(int xa, int ya)
{
    X += xa;
    Y += ya;
}