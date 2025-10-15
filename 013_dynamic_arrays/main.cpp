/*
    C++ 动态数组

    本节中，需要知道：

    - std::vector 的工作原理
      创建一个 vector 时，会分配一个默认的容量，这个容量会根据 vector 的使用情况自动调整
    
    - std::vector 的容量优化
      reserve() 提前分配容量，避免扩容时进行复制操作延缓效率
    
    - std::vector 的 emplace_back()
      push_back() 会进行内存复制，而 emplace_back() 直接讲参数传入 vector 原地构造，避免复制
    
    总结：std::vector 并不是很高效，很多团队会自己实现一个 vector, 选择 C++ 就是为了选择优化效率！
*/
#include <iostream>
#include <vector>
#include "src/Vector.h"

struct Vertex
{
    float x = 0.0f, y = 0.0f, z = 0.0f;

    Vertex(float x, float y, float z)
        : x(x), y(y), z(z)
    {
        //std::cout << "Created!" << std::endl;
    }

    Vertex(const Vertex& other) // 复制构造函数
        : x(other.x), y(other.y), z(other.z)
    {
        std::cout << "Copyed!" << std::endl;
    }
};

std::ostream& operator<<(std::ostream& os, const Vertex& v) // 重载 <<
{
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

void printVertices(const std::vector<Vertex>& vertices)
{
    for (const auto& v : vertices)
    {
        std::cout << v << "\n";
    }
}
void printVertices(const Vector<Vertex>& vertices)
{
    for(size_t i = 0; i < vertices.size(); i++)
    {
        std::cout << vertices[i] << "\n";
    }
}

int main()
{
    std::vector<Vertex> stdVertices;
    
    std::cout << "std::vector with push_back : \n";
    
    stdVertices.push_back(Vertex(1, 2, 3)); // main 中构造好的 Vertex 传入 vector 有一个复制
    stdVertices.push_back(Vertex(4, 5, 6));
    stdVertices.push_back(Vertex(7, 8, 9)); // 扩容的时候有复制

    printVertices(stdVertices);

    std::cout << "---------------------" << std::endl;
    
    std::cout << "std::vector with emplace_back : \n"; 

    stdVertices.clear();
    stdVertices.reserve(3); // 提前分配容量
    stdVertices.emplace_back(1, 2, 3); // 直接传入参数在 vector 中原地构造，避免复制
    stdVertices.emplace_back(4, 5, 6);
    stdVertices.emplace_back(7, 8, 9);

    printVertices(stdVertices);

    std::cout << "---------------------" << std::endl;

    Vector<Vertex> myVertices;

    std::cout << "my vector with push_back : \n";
    
    myVertices.push_back(Vertex(1, 2, 3));
    myVertices.push_back(Vertex(4, 5, 6));
    myVertices.push_back(Vertex(7, 8, 9));

    printVertices(myVertices);

    std::cout << "---------------------" << std::endl;

    std::cout << "my vector with emplace_back : \n";

    myVertices.pop_back();
    myVertices.pop_back();
    myVertices.pop_back();
    myVertices.emplace_back(1, 2, 3);
    myVertices.emplace_back(4, 5, 6);
    myVertices.emplace_back(7, 8, 9);

    printVertices(myVertices);
}