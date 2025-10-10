/*
    C++ Lambda 函数

    本节中，需要知道:

    - Lambda 函数的定义
      匿名函数对象，提供了更简洁的语法来创建局部可调用的函数实体。它们能捕获上下文变量
    
    - Lambda 语法
      auto lambda = [](int a, int b) -> int {return a * b;}
      通常可省略返回类型，编译器自动推导

    - 捕获列表
      Lambda 的一大特性就是可以捕获上下文的变量, [] 为捕获列表
      
      捕获方式	     语法	    变量状态	        是否可修改
      值捕获	     [x]	    副本	        Lambda内部不可改
      引用捕获	     [&x]	    引用	        Lambda内部可改
      隐式值捕获	  [=]	   所有变量副本	        默认不可改
      隐式引用捕获	  [&]	   所有变量引用	          可修改
      混合捕获	    [x, &y]	    混合	           各自规则
      this捕获	    [this]	  成员访问	          可修改成员
    
    - std::function
      C++ 函数对象容器，它可以保存任意可调用对象，并执行它们
      类似函数指针，但可以保存任意可调用对象, 一般搭配 Lambda 使用
      头文件 #include <functional>

    总结: 对于需要上下文访问、状态管理的轻量级函数，Lambda提供了更加优雅高效的解决方案
*/

#include <iostream>

void ForEach(std::vector<int> &values, std::function<void(int)> func)
{
    // 遍历元素, 应用 func
    for (int &v : values)
    {
        func(v);
    }
}

int main()
{
    std::vector<int> values = {1, 2, 3, 4, 5}; 

    auto print = [&](int a) { std::cout << a << std::endl; }; // 定义 Lambda
    ForEach(values, print);

    auto it = std::find_if(values.begin(), values.end(), [](int a) { return a > 3; }); // Lambda 搭配 find_if 使用
    std::cout << *it << std::endl;
}