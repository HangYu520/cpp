#pragma once
#include <iostream>

class Log
{
public:
    enum Level
    {
        ERROR = 0,
        WARNING = 1,
        INFO = 2
    };

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
