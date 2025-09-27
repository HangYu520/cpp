#pragma once
#include <iostream>

class Log
{
public:
    enum Level // 枚举：一组整数常量
    {
        ERROR, WARNING, INFO
    };

    //const int ERROR = 0;
    //const int WARNING = 1;
    //const int INFO = 2;

private:
    int m_LogLevel = INFO;

public:
    Log();
    
    ~Log();

    void SetLevel(int level);
    
    void Warning(const char* message);
    
    void Error(const char* message);
    
    void Info(const char* message);
};
