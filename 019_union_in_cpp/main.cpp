/*
    C++ 联合体 (Union)

    本节中, 需要知道:

    - union 的作用
      一种特殊的结构体, 所有的成员变量都存放在同一个地址空间中, 访问时, 只能访问其中一个成员变量

    - 匿名 union
      一个常见用法是创建一个匿名 union, 可以直接通过不同的方式调用匿名 union 的成员变量
*/

#include <iostream>
#define print(x) std::cout << x << std::endl

union u_Vec2
{
    float X, Y; // 实际只有 1 个 float
};

struct Vec2
{
    float X, Y;
};

struct Vec4
{
    union
    {   // 2 种方式获取 Vec4 的分量
        struct
        {
            float X, Y, Z, W;
        }; // 4 个 float

        struct
        {
            Vec2 XY, ZW;
        }; // 2 个 Vec2
    };
    
};

int main()
{ 
    print("sizeof(u_Vec2) = " << sizeof(u_Vec2));
    print("sizeof(Vec2) = " << sizeof(Vec2));
    print("sizeof(Vec4) = " << sizeof(Vec4));

    Vec4 v4d = {1.0f, 2.0f, 3.0f, 4.0f};
    print(v4d.X << " " << v4d.Y << " " << v4d.Z << " " << v4d.W);
    print(v4d.XY.X << " " << v4d.XY.Y << " " << v4d.ZW.X << " " << v4d.ZW.Y); //2 种方式获取 Vec4 的分量
}