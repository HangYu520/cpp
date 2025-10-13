#pragma once
#include <iostream>

class String // 自定义字符串类
{
private:
    char* m_data;
    uint32_t m_size;

public:
    String();
    ~String(); // 析构函数
    String(const char* str); // 构造函数
    
    //* 拷贝
    String(const String& other); // 拷贝构造函数
    String& operator=(const String& other); // 拷贝赋值运算符
    
    //* 移动
    String(String&& other); // 移动构造函数
    String& operator=(String&& other); // 移动赋值运算符

    // *运算符重载
    String operator+(const String& other); // 加法运算符重载
    friend std::ostream& operator<<(std::ostream& stream, const String& str); // 友元函数
};
