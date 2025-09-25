/* 
    C++ 编程环境: VS CODE + GCC + CMake

    本节中, 需要知道:
    
    - 如何在 VS CODE 中编译和调试 C++ code ?
      
      关键是要修改 'launch.json' 文件

    - 如何编写 CMAKELists 文件 ?

      详见 https://blog.csdn.net/iuu77/article/details/129229361
*/

#include <iostream>

void Log(const char *message);

int main()
{
    Log("Hello World!");
    std::cin.get();
}