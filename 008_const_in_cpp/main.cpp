/*
    C++ 常量 (const)

    本节中，需要知道:

    - const 定义指针
      const int* ptr: 内容不可变，指针可变
      int *const ptr: 内容可变，指针不可变
    
    - 类的 const 成员函数
      类的函数被标明为 const，则该函数不能修改类的成员变量
      使用 mutable 可以使得 const 成员函数修改类成员变量
*/

#include <iostream>

class Entity
{
private:
    int m_X, m_Y;
    mutable int count = 0;

public:
    Entity()
    {
        m_X = m_Y = 0;
    }
    
    ~Entity()
    {}

    int get_X() const
    {
        count++; // count 是 mutable
        return m_X; //不能修改
    }

    int get_X()
    {
        m_X = 10; //可以修改
        return m_X;
    }
};

void printXconst(const Entity& entity) // entity 是 const, 不能修改
{
    std::cout << entity.get_X() << std::endl; // 只能调用无法修改的 get_X
}

void printX(Entity& entity) // entity 不是 const, 可以修改
{
    std::cout << entity.get_X() << std::endl; // 调用修改 get_X
}

int main()
{
    Entity e;
    printXconst(e);
    printX(e);
}