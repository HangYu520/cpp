/* 
    C++ 指针和引用

    本节中, 需要知道:

    - 指针的含义
      指向内存的地址，可以不初始化，且随时改变指向
      const int *ptr; 内容不可变，指针可变
      int *const ptr; 内容可变，指针不可变
    
    - 指针的使用 (*ptr)
      *是取址运算符，取出指针(地址)的内容
    
    - 引用的含义
      指向内存的变量，变量的另一个名称
      必须初始化，且一旦定义，无法修改
    
    本质上，引用就是一个不能修改指向的指针，所以引用能做的指针都能做
    但是，一般优先使用引用，因为引用更安全，简洁
*/
#include <iostream>
#define LOG(x) std::cout << x << std::endl

void increment(int& val)
{
    val++;
}

int main()
{
    int var = 8;
    int* ptr = &var; 
    *ptr = 10;
    LOG(var);

    increment(var);
    LOG(var);
}