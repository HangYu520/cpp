/*
    C++ New 关键字

    本节中，需要知道:

    - new 的作用
      在堆上分配内存, 必须使用 delete 释放内存
      堆分配和栈分配是 C++ 内存管理中的重要概念
      栈分配的内存(小)是连续的, 堆分配的内存(大)是碎片化的
      因此堆分配引入的额外操作更多，更加影响性能
      在实时性要求很高的应用中，尽量优化堆分配从而进行有效的内存管理也是很重要的一个技能

      如 std::string 的实现原理就是使用 new 创建对象
      因此如何处理好 string 减少内存分配次数，也是 C++ 高级 technic 中的一个技能
      如 std::string_view, small string optimization 等，感兴趣自行搜索 ！
    
    - 和 malloc() 的区别
      new 创建对象, malloc 创建内存, 不会调用构造函数
      new 是 C++ 运算符，拥有 C++ 特性，如重载

    - 为什么需要重载 new/delete 运算符
      在实时性要求高的应用中，尽量优化堆分配从而进行有效的内存管理
      这时候重载 new 运算符，可以追踪、控制对象创建和销毁的时机，从而达到有效的内存管理

    内存管理是 C++ 的一个重要特性，也是为什么写 C++ 的一个主要原因 ！
*/

#include <iostream>

struct MeomoryAllocator
{
    static int Allocatebytes;
    static int Freebytes;
};

int MeomoryAllocator::Allocatebytes = 0;
int MeomoryAllocator::Freebytes = 0;

static void print_meomory()
{
    std::cout << "Meomory Usage : " << MeomoryAllocator::Allocatebytes - MeomoryAllocator::Freebytes << std::endl;
}

void* operator new(size_t size) // 重载 new 运算符
{
    MeomoryAllocator::Allocatebytes += size;
    return malloc(size);
}

void operator delete(void* memory) noexcept // 重载 delete 运算符
{
    MeomoryAllocator::Freebytes += sizeof(memory);
    free(memory);
}

class Entity
{
public:
    int X, Y;

    Entity()
        : X(0), Y(0)
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
    print_meomory();
    std::cout << "Test the new keyword" << std::endl;
    Entity* e1 = new Entity();
    print_meomory();
    delete e1;
    print_meomory();

    std::cout << "Test the malloc keyword" << std::endl;
    Entity* e2 = (Entity*)malloc(sizeof(Entity)); // malloc() 创建内存, 不会调用构造函数
    free(e2);
}