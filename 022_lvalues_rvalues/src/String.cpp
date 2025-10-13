#include "String.h"


String::String(const char* str) // * 构造函数
{
    std::cout << "Created : " << str << std::endl;
    m_size = strlen(str);
    m_data = new char[m_size + 1];
    memcpy(m_data, str, m_size);
    m_data[m_size] = '\0';
}

String::String()
    : m_data(nullptr), m_size(0)
{
    std::cout << "Default Created" << std::endl;
}

String::~String() // * 析构函数
{
    if(m_data)
    {
        std::cout << "Destroyed : " << m_data << std::endl;
        delete[] m_data;
    }
}

String::String(const String& other) // * 拷贝构造函数
{
    std::cout << "Copied !" << std::endl;
    m_size = other.m_size;
    m_data = new char[m_size + 1];
    memcpy(m_data, other.m_data, m_size + 1);
}

String& String::operator=(const String& other) // * 拷贝赋值运算符
{
    std::cout << "Copy Assigned!" << std::endl;
    if (this != &other) // * 避免自赋值
    {
        char* new_data = new char[other.m_size + 1];
        memcpy(new_data, other.m_data, other.m_size + 1);
        if (m_data) delete[] m_data;
        m_data = new_data;
        m_size = other.m_size;
    }
    return *this;
}

String::String(String&& other) // * 移动构造函数
{
    // * m_data 接管 other.m_data 的所有数据, other 直接 null, 因为它是一个右值, 无关紧要
    std::cout << "Moved !" << std::endl;
    m_size = other.m_size;
    m_data = other.m_data;
    
    other.m_data = nullptr;
    other.m_size = 0;
}

String& String::operator=(String&& other) // * 移动赋值运算符
{
    std::cout << "Move Assigned !" << std::endl;
    if (this != &other) // * 避免自赋值
    {
        m_size = other.m_size;
        m_data = other.m_data;
        
        other.m_data = nullptr;
        other.m_size = 0;
    }
    return *this;
}

String String::operator+(const String& other) // * 加法运算符重载
{
    char* new_data = new char[m_size + other.m_size + 1];
    memcpy(new_data, m_data, m_size);
    memcpy(new_data + m_size, other.m_data, other.m_size);
    new_data[m_size + other.m_size] = '\0';
    return String(new_data);
}

std::ostream& operator<<(std::ostream& stream, const String& str) // * 重载 <<
{
    if(str.m_data) stream << str.m_data;
    return stream;
}