/*
    C++ 虚函数 (Virtual)

    本节中，需要知道：

    - 虚函数的定义
      父类定义虚函数，子类中可以进行重写这个函数
      允许父类的指针调用子类重写后的虚函数
      重写时添加关键词 override 增强可读性

    - 虚函数的底层实现
      编译器会为父类添加一个虚函数表，用以维护对应关系

    - 纯虚函数
      纯虚函数在父类中声明，在子类中必须进行重写
      含有纯虚函数的类，不能实例化，称为抽象类 (Abstract Class)

    - 为什么需要使用纯虚函数？
      需要一个接口类，希望所有子类都必须实现这个接口
*/

#include <iostream>

class Shape
{
public:
    Shape(){};

    ~Shape(){};

    virtual void Draw() = 0; //子类必须实现
};

class Circle : public Shape
{
public:
    Circle(){};

    ~Circle(){};

    void Draw() override
    {
        std::cout << "Draw a Circle !" << std::endl;
    }
};

class Rectangle : public Shape
{
public:
    Rectangle(){};

    ~Rectangle(){};

    void Draw() override
    {
        std::cout << "Draw a Rectangle !" << std::endl;
    }
};

void DrawShape(Shape *shape)
{
    shape->Draw(); // Shape 必须是可 Draw 的
}

int main()
{
    //Shape *shape = new Shape(); // 无法实例化抽象类
    Shape *circle = new Circle(); 
    Shape *rectangle = new Rectangle();

    DrawShape(circle);
    DrawShape(rectangle);
}