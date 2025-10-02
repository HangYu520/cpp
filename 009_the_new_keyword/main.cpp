/*
    C++ New 关键字

    本节中，需要知道:

    - new 的作用
      在堆上分配内存, 必须使用 delete 释放内存
    
    - 和 malloc() 的区别
      new 创建对象, malloc 创建内存, 不会调用构造函数
    
    new 和 delete 的本质是运算符，支持重载
*/

#include <iostream>

class Entity
{
public:
    Entity()
    {
        std::cout << "Created Entity!" << std::endl;
    }

    ~Entity()
    {
        std::cout << "Destroyed Entity!" << std::endl;

    }
};

int main()
{
    std::cout << "Test the new keyword" << std::endl;
    Entity* e1 = new Entity();
    delete e1;

    std::cout << "Test the malloc keyword" << std::endl;
    Entity* e2 = (Entity*)malloc(sizeof(Entity)); // malloc() 创建内存, 不会调用构造函数
    free(e2);
}