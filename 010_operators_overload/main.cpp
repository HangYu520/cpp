/*
    C++ 运算符重载

    本节中，需要知道:

    - 运算符重载的方法

    - << 的重载方法
      类外的非成员函数，要访问 private 成员变量，需要使用友元函数
*/

#include <iostream>

struct Vec3
{
    float x, y, z;

    Vec3(float x, float y, float z): x(x), y(y), z(z) {}

    Vec3 Add(const Vec3& other) const
    {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

    Vec3 operator+(const Vec3& other) const
    {
        return this->Add(other);
    }

    Vec3 Multiply(const Vec3& other) const
    {
        return Vec3(x * other.x, y * other.y, z * other.z);
    }

    Vec3 operator*(const Vec3& other) const
    {
        return this->Multiply(other);
    }

    bool operator==(const Vec3& other) const
    {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator!=(const Vec3& other) const
    {
        return !(*this == other);
    }
};

std::ostream& operator<<(std::ostream& stream, const Vec3& vector)
{
    stream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
    return stream;
}

int main()
{ 
    Vec3 a(1.0f, 2.0f, 3.0f);
    Vec3 b(2.0f, 3.0f, 4.0f);

    Vec3 c = a.Add(b);
    Vec3 d = a + b;

    std::cout << c << std::endl;
    std::cout << d << std::endl;

    std::cout << (a == b) << std::endl;
}