/*
    C++ 复制构造函数

    本节中，需要知道：

    - 拷贝构造函数
      在拷贝对象时，C++会调用拷贝构造函数，C++ 默认实现了浅拷贝

    - 浅拷贝
      浅拷贝只拷贝了成员变量，对于指针类型成员变量，只拷贝了指针的值，而不是指针所引用的对象
    
    - 深拷贝
      在一些情况下，我们手动实现深拷贝，即拷贝指针所引用的内存，而不是拷贝指针本身
*/

#include <iostream>

class String //手动实现简单的 string 类
{
private:
    char* m_buffer;
    unsigned int m_size;

public:
    String(const char* string)
    {
        m_size = strlen(string);
        m_buffer = new char[m_size + 1];
        memcpy(m_buffer, string, m_size);
        m_buffer[m_size] = '\0'; //必须添加字符串结束符
    }

    String(const String& other)
    {   // 拷贝构造函数, 实现深拷贝
        m_size = other.m_size;
        m_buffer = new char[m_size + 1];
        memcpy(m_buffer, other.m_buffer, m_size+1);
    }

    ~String()
    {
        delete[] m_buffer; //浅拷贝只复制指针的情况下, 会释放两次同一块内存，错误！
    }

    char& operator[](unsigned int index)
    {
        return m_buffer[index];
    }

    friend std::ostream& operator<<(std::ostream& out, const String& string);
};

std::ostream& operator<<(std::ostream& out, const String& string)
{
    out << string.m_buffer;
    return out;
}

int main()
{ 
    String first_str = "Hello World!";
    String second_str = first_str; // 调用拷贝构造函数, 默认浅拷贝

    second_str[1] = 'a'; // 浅拷贝时，两个都会修改

    std::cout << first_str << std::endl;
    std::cout << second_str << std::endl;
}