/* 
    C++ 类和结构体

    本节中, 需要知道:

    - 类的定义和声明
    - 类的私有和公有成员
    - 类的继承
    - 结构体的定义和声明
    - 结构体的继承

    结构体和类的唯一区别就是：结构体成员默认是公有的，而类成员默认是私有的。
    struct = public class

    一般来说，我们使用类来定义对象，使用结构体来定义数据集合(打包)。
*/

#include "src/Player.h"
#include "src/Log.h"

struct Vec2
{
    int x, y;

    Vec2(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    void add(const Vec2& v)
    {
        x += v.x;
        y += v.y;

    }
};


int main()
{
    Player player(2, 3, 5);
    player.move(1, 1);
    player.log();

    Vec2 v1(1, 2), v2(2, 3);
    v1.add(v2);
    LOG("x:"<< v1.x << ", y:"<< v1.y);

    Log log;
    log.Info("This is an info message");
}