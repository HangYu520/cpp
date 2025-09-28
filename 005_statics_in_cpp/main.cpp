/* 
    C++ 静态(static)

    本节中, 需要知道:

    - 类和结构体外使用 static
      静态全局变量, 所声明的静态对象, 仅在对应的编译单元中可见
      静态局部变量（在函数内部）只初始化一次，即使函数多次调用，变量值也会保持
    
    - 类和结构体内使用 static
      所有的实例, 共享所申明的静态对象
*/

#include <iostream>
int s_variable = 10;

struct Entity
{
    static int x, y; // 所有实例共享
    void print()
    {
        std::cout << x << ", " << y << std::endl;
    }
};

int Entity::x; //必须在外部申明初始化
int Entity::y;

void counter()
{
    static int count = 0; // 静态局部变量, 不死亡，只初始化一次
    std::cout << ++count << std::endl;
}

int main()
{
    std::cout << s_variable << std::endl;

    Entity e1;
    e1.x = 5;
    e1.y = 8;

    Entity e2;
    e2.x = 10;
    e2.y = 20;

    e1.print();
    e2.print();

    counter();
    counter();
    counter();
}