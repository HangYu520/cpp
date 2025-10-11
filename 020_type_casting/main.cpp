/*
    C++ 类型转换

    本节中，需要知道：

    - 隐式转换
      编译器支持隐式转换，不用声明，自动转换 int a = 5.25;
      如直接赋值构造函数参数，不需要显式调用构造函数
      构造函数添加 explicit 关键字，则不能隐式转换

    - 显式转换
      C 风格的显式转换完全兼容 C++ 语言，如 int a = (int) 5.25;
      但存在安全性问题，缺乏类型检查，且在代码中难以大规模搜索
      所以 C++ 引入类型转换函数, 主要包含 4 种

    - static_cast
      静态转换，编译时检查，如 int a = static_cast<int>(5.25);
      在转换时编译器添加了一个检查步骤
    
    - const_cast
      常量转换，将常量转换为非常量, 只处理指针和引用
    
    - reinterpret_cast
      重新转换，将指针转换为其他指针类型, 即重新解释内存块
    
    - dynamic_cast
      动态转换，设计多态类型的转换，添加了运行时检查
      成功返回指针，失败返回 NULL

    类型转换函数没有添加新功能，只是使得转换更加方便，原有的 C 风格转换也完全可行
*/

#include <iostream>
#define PRINT(x) std::cout << x << std::endl

class Base
{
public:
    Base(){}
    virtual ~Base(){}
};

class Derived1 : public Base
{
public:
    const int FLAG = 1;
    Derived1(){}
    ~Derived1(){}

    void print()
    {
        PRINT("Derived1");
    }
};

class Derived2 : public Base
{
public:
    const int FLAG = 2;
    Derived2(){}
    ~Derived2(){}

    void print()
    {
        PRINT("Derived2");
    }
};

int main()
{
    // int a = 5.25; // 隐式转换, 会提示 warning
    int b = (int) 5.25; // C 风格显式转换
    int c = static_cast<int>(5.25); // 静态转换
    PRINT("b=" << b); PRINT("c=" << c); 

    const int *d = new const int(5); // 不可修改
    int *e = const_cast<int *>(d); // 常量转换
    *e = 10; // 修改
    PRINT("*d=" << *d); PRINT("*e=" << *e);
    delete e;

    Derived1 *derivied1 = new Derived1();
    Derived2 *derivied2 = reinterpret_cast<Derived2 *>(derivied1); // 重新解释，但内存还是 Derived1

    Base *base = new Derived1();
    Derived2 *d1 = static_cast<Derived2 *>(base); // 转换成功，但实际内存还是 Derived1
    Derived2 *d2 = dynamic_cast<Derived2 *>(base); // 判断内存是 Derived1, 不可转换，返回 NULL
    PRINT(base); PRINT(d1); PRINT(d2);
}