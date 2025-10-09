/*
    C++ 模版 (template)

    本节中，需要知道:

    - 模版的作用
      为不同的数据类型提供同一套函数或类

    - 模版的语法
      template <typename T, ...>
      模版参数不一定是未知类型, 也可以是已知类型
      模版参数可以是多个
      模版在被调用之前实际上不存在, 即不被编译器看见
      因为模版只是一个草图，不是实际的代码，编译器在编译时原地生成, 所以声明和实现必须放在一起
      一般都放在头文件中，因为如果放在 cpp 文件中其他使用了模版的 cpp 看不见

    模版是一个很强大的功能，但是也不要过度使用
*/

#include <iostream>

template <typename T, int N> // 模版参数可以是多个
class Array
{ 
private:
    T m_array[N];

public:
    int size() const
    {
        return N;
    }

    void print() const
    {
        for (int i = 0; i < N; i++)
        {
            std::cout << m_array[i] << " ";
        }
        std::cout << std::endl;
    }

    T& operator[](int index)
    {
        return m_array[index];
    }
};

int main()
{
    Array<int, 3> intArray;
    intArray[0] = 1;
    intArray[1] = 2;
    intArray[2] = 3;
    intArray.print();

    Array<char, 5> charArray;
    charArray[0] = 'h';
    charArray[1] = 'e';
    charArray[2] = 'l';
    charArray[3] = 'l';
    charArray[4] = 'o';
    charArray.print();
}