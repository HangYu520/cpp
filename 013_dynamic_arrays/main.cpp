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

struct Vertex
{
    float x, y, z;

    Vertex(float x, float y, float z)
        : x(x), y(y), z(z)
    {
        //std::cout << "Created!" << std::endl;
    }

    Vertex(const Vertex& other)
        : x(other.x), y(other.y), z(other.z)
    {
        std::cout << "Copyed!" << std::endl;
    }
};

std::ostream& operator<<(std::ostream& os, const Vertex& v)
{
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

int main()
{
    std::vector<Vertex> vertices;
    vertices.push_back(Vertex(1, 2, 3)); // main 中构造的 Vertex 传入 vertices 有一个复制操作
    vertices.push_back(Vertex(4, 5, 6));
    vertices.push_back(Vertex(7, 8, 9)); // 扩容的时候有复制操作

    std::cout << "Optimized!" << std::endl;

    std::vector<Vertex> vertices2;
    vertices2.reserve(3); // 提前分配容量
    vertices2.emplace_back(1, 2, 3); // 直接传入参数在 vertices 中原地构造，避免复制
    vertices2.emplace_back(4, 5, 6);
    vertices2.emplace_back(7, 8, 9);
}