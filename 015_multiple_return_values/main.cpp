/*
    C++ 合并多返回值

    本节中，需要知道：

    - 多变量作为函数参数传入，在函数内修改
      更新时存在复制的问题

    - 以数组的形式打包返回多个变量
      需要返回值是同一类型的变量

    - std::tuple 打包多个变量
      头文件 #include <tuple>
    
    - std::pair 存放两个变量
      头文件 #include <utility>

    - 以结构体打包返回多个变量

    更推荐以结构体打包返回，因为可以命名变量，更清晰
*/

#include <iostream>
#include <tuple>
#include <utility>
#include <format>
#define print(x) std::cout << x << std::endl;

void area_perimeter1(float radius, float &area, float &perimeter)
{
    // 以参数的方式返回多个变量
    area = 3.14 * radius * radius;
    perimeter = 2 * 3.14 * radius;
}

std::tuple<float, float> area_perimeter2(float radius)
{
    // 以 tuple 打包返回多个变量
    return std::make_tuple(3.14 * radius * radius, 2 * 3.14 * radius);
}

std::pair<float, float> area_perimeter3(float radius)
{
    // 以 pair 存放两个变量
    return std::make_pair(3.14 * radius * radius, 2 * 3.14 * radius);
}

struct Circle
{
    float area;
    float perimeter;
};

Circle area_perimeter4(float radius)
{
    // 以结构体打包返回多个变量
    float area = 3.14 * radius * radius;
    float perimeter = 2 * 3.14 * radius;
    return {area, perimeter};
}

int main()
{ 
    float radius = 5.0;

    float area, perimeter;

    area_perimeter1(radius, area, perimeter);
    print(std::format("area: {}, perimeter: {}", area, perimeter));

    auto circle_tuple = area_perimeter2(radius); // 使用自动推断类型 auto
    print(std::format("area: {}, perimeter: {}", std::get<0>(circle_tuple), std::get<1>(circle_tuple)));

    auto circle_pair = area_perimeter3(radius);
    print(std::format("area: {}, perimeter: {}", circle_pair.first, circle_pair.second));

    Circle circle = area_perimeter4(radius);
    print(std::format("area: {}, perimeter: {}", circle.area, circle.perimeter)); // 有命名更清晰
}