/*
    C++ 智能指针

    本节中，需要知道:

    - 什么是智能指针
      智能指针，是指程序员使用指针时，不需要自己管理指针所引用的对象，当指针不再被使用，对象也会被销毁。
      即 自动化内存管理, 避免手动 delete 掉 new 的内存

    - unique_ptr
      单一所有权, 不可复制, 自动销毁, 无需 delete
    
    - shared_ptr
      多个所有权, 可复制, 自动销毁, 无需 delete
      采用引用计数的方式实现, 当复制时，引用计数加1
      所有的引用都销毁时，对象才会被销毁
    
    - weak_ptr
      弱引用, 弱指针, 线程安全
      复制时，引用计数不变

    总结: 优先使用 unique_ptr, shared_ptr 由于引用计数，有额外的开销
    weak_ptr 的作用是在不影响对象生命周期时，观察对象的状态 (一个观察者)

    weak_ptr 还避免了循环引用, 即 shared_ptr 相互引用成一个环, 导致引用计数不为0

    最后: 有了智能指针，不代表就不需要再使用 new 和 delete 了!
*/

#include <iostream>
#include <memory>

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

class ScopedPtr // unique_ptr 的示例
{
private:
    Entity* m_Ptr;

public:
    ScopedPtr(Entity* ptr)
        : m_Ptr(ptr)
    {
    }

    ~ScopedPtr()
    {
        delete m_Ptr;
    }
};

int main()
{
    Entity* ptr;
    {
        ptr = new Entity(); // new Entity()
        std::cout << "ScopedPtr created" << std::endl;
        ScopedPtr sp(new Entity()); // free memeory automatically
    }

    delete ptr; // must delete manually

    std::cout << "SmakePtr created" << std::endl;

    std::weak_ptr<Entity> ptr2;
    {
        std::unique_ptr<Entity> uni_ptr = std::make_unique<Entity>(); // == ptr(new Entity())
        // ptr2 = uni_ptr; // can not copy
        std::shared_ptr<Entity> sha_ptr = std::make_shared<Entity>();
        ptr2 = sha_ptr; // can copy, but only observe the state
    }
    std::cout << "weak_ptr count: " << ptr2.use_count() << std::endl;
}