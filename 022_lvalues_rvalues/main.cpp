/*
    C++ 左值和右值

    本节中, 需要知道:

    - 左值右值的定义
      左值: 拥有持久身份的对象, 可以通过 & 获取其地址
      右值: 生命周期仅在表达式执行期间, 不可寻址, 只能出现在等式的右侧
      简单来说, 右值是临时对象, 左值是持久对象
    
    - 左值引用
      T& 只可以引用左值（判断是否是左值的一个方法）
      const T& 可以引用左值和右值
    
    - 右值引用
      T&& 只可以引用右值
    
    - 移动语义
      移动语义是一种优化, 允许对象在赋值时, 避免复制数据
      移动语义通过左值来接管右值的数据, 从而避免了复制操作所开辟的内存
      移动构造函数, 移动赋值运算符, 都是移动语义需要实现的函数

    - std::move
      将左值转为右值引用, static_cast<T&&> lvalues, 从而进行移动操作

    总结: 引入 左值、右值、移动 的目的就是为了优化程序性能, 避免不必要的复制(深拷贝)所导致的内存开销

    原本的值在移动后就空了, 若原本非右值, 需要注意变量丢失！
*/

#include <iostream>
#include "src/String.h"

void print(String& str) // *左值引用
{
    std::cout << "[lvalue] : " << str << std::endl;
}

void print(String&& str) // * 右值引用
{
    std::cout << "[rvalue] : " << str << std::endl;
}

int main()
{
    String first_str = "Hello";
    String second_str = "World";
    print(first_str); // 左值
    print(first_str + second_str); // 右值: + 返回的是一个临时对象

    std::cout << "-----------------------------------" << std::endl;
    // ! first_str + second_str 返回了一个临时对象, 所以这个复制完全可以不需要

    String str1; // 默认构造函数
    str1 = first_str + second_str; // 右值触发移动

    std::cout << "-----------------------------------" << std::endl;
    
    String str2;
    str2 = first_str; // 复制, 因为 first_str 是左值
    
    std::cout << "first str "; print(first_str);
    
    str2 = std::move(first_str); // 移动
    
    std::cout<< "first str "; print(first_str); // first_str 被移动了, 所以为空
    std::cout<< "str2 "; print(str2);
    
}