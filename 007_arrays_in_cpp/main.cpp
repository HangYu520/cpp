/*
    C++ 数组 (Arrays)

    本节中, 需要知道:

    - 数组的定义
    - 使用 new 定义数组
    - std::array

    在函数内部定义数组并返回时, 需要使用 new 创建数组并返回，否则会丢失。
*/

#include <iostream>

class DynamicArray
{
public:
    int *array;
    
    int arraySize, item;

public:
    DynamicArray(int size)
    {
        item = 0;
        arraySize = size;
        array = new int[size];
    }

    ~DynamicArray()
    {
        delete[] array; // 释放内存
    }

    void append(int value)
    {
        if (item > arraySize - 1)
        {
            arraySize *= 2;
            int *newarray = new int[arraySize];

            for (int i = 0; i < item; i++)
            {
                newarray[i] = array[i];
            }
            
            delete[] array;
            array = newarray;
        }
        array[item++] = value;
    }

    void print()
    {
        for (int i = 0; i < item; i++)
        {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    DynamicArray Array(3);
    Array.append(1);
    Array.append(2);
    Array.append(3);
    Array.append(4);
    Array.print();
}