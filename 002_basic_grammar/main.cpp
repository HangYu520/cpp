/* 
    C++ 编程的基础语法

    本节中, 需要知道:
    
    - 变量的定义
    - 函数的定义
    - 头文件的使用
    - 条件语句的使用
    - 循环语句的使用
    - 控制流的使用
*/
#include <iostream>
#include "src/Myfunc.h"
#include "src/Myfunc.h"

int main()
{
    if (0)
    {
        multiplyAndlog(2, 3);
    }
    else
    {
        std::cout << "else" << std::endl;
    }

    for (size_t i = 0; i < 2; i++)
    {
        if (i == 1)
        {
            break;
        }
        
        multiplyAndlog(2, 3);
    }
    
}