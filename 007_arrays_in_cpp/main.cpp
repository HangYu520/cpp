/*
    C++ 数组 (Arrays)

    本节中, 需要知道:

    - 数组的定义
    - 使用 new 定义数组
    - std::array

    在函数内部定义数组并返回时, 需要使用 new 创建数组并返回，否则会丢失。
*/

#include <iostream>
#include <array>

template <typename T, size_t N> // 自定义数组模板
struct Array 
{
    T _array[N];

    T& operator[](size_t index) // 重载下标运算符
    {
        return _array[index];
    }

    T size() const // 返回数组大小
    {
        return N;
    }

    T* begin() // 返回数组首地址
    {
        return &_array[0];
    }

    T* end() // 返回数组尾地址
    {
        return &_array[N];
    }

};

void printArray(const int* array, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int stackArray[5] = {1, 2, 3, 4, 5}; // 栈中定义的数组
    int *heapArray = new int[5] {1, 2, 3, 4, 5}; // 堆中分配的数组
    std::cout << "Stack Array: ";
    printArray(stackArray, 5);
    std::cout << "Heap Array: ";
    printArray(heapArray, 5);
    delete[] heapArray;

    std::cout << "-------------------------" << std::endl;

    Array<int, 5> array;
    std::cout << "Array before assignment: ";
    printArray(array.begin(), array.size());
    for (size_t i = 0; i < array.size(); i++)
    {
        array[i] = i + 1;
    }
    std::cout << "Array after assignment: ";
    printArray(array.begin(), array.size());
}