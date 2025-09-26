#include "Log.h"

Log::Log()
{
    
}

Log::~Log()
{
    
}

void Log::SetLevel(int level)
{
    m_LogLevel = level;
}

void Log::Warning(const char* message)
{
    if (m_LogLevel >= WARNING)
        std::cout << "[WARNING]: " << message << std::endl;
}

void Log::Error(const char* message)
{
    if (m_LogLevel >= ERROR)
        std::cout << "[ERROR]: " << message << std::endl;
}

void Log::Info(const char* message)
{
    if (m_LogLevel >= INFO)
        std::cout << "[INFO]: " << message << std::endl;
}