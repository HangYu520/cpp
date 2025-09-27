/* 
    C++ 类和结构体

    本节中, 需要知道:

    - 类的定义和声明
      构造函数和析构函数
    
    - 类的私有和公有成员
      private 和 protected 的区别是子类是否有权限访问，private 不能

    - 类的继承
      一般是 public 继承, 也有 private 继承，protected 继承
      继承时先调用父类的构造函数，然后调用子类的构造函数
      析构函数是先调用子类的析构函数，然后调用父类的析构函数
    
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

    void add(const Vec2& v)
    {
        x += v.x;
        y += v.y;

    }
};


int main()
{
    {
        Player player(0, 0, "Bob");
        player.move(1, 1);
        player.log();
    }

    Vec2 v1={1, 2}, v2={2, 3};
    v1.add(v2);
    LOG("x:"<< v1.x << ", y:"<< v1.y);

    Log log;
    int level = Log::Level::INFO;
    std::cout << level << std::endl;
    log.Info("This is an info message");
}