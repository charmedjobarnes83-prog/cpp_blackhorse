#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

//普通函数
int add(int a, int b) {
    return a + b;
}

//仿函数
struct Multiply {
    int operator()(int a, int b) const {
        return a * b;
    }
};

//Lambda表达式
auto subtract = [](int a, int b) {return a - b;};

//类定义
class Calculator {
public:
    int subtract(int a, int b) {
        return a - b;
    }
    void displayoperation(const std::string& op, int result) {
        std::cout << op << " " << result << std::endl;
    }
};

//静态成员函数
class Logger {
public:
    static void Log(const std::string& message) {
        std::cout << "log: " << message << std::endl;
    }
};

int main() {
    //函数指针
    int (*func1)(int, int) = add;
    std::cout << func1(4, 3) << std::endl;

    //仿函数
    Multiply m1;
    std::cout << m1(5, 6) << std::endl;

    //Labmda
    std::cout << subtract(6, 2) << std::endl;

    //function
    std::function<int(int, int)> funcadd = add;
    std::function<int(int, int)> funcmul = m1;
    std::function<int(int, int)> funcsub = subtract;

    std::cout << funcadd(5, 6) << std::endl;
    std::cout << funcmul(2, 3) << std::endl;
    std::cout << funcsub(9, 6) << std::endl;

    //bind
    auto add5 = std::bind(add, 5, std::placeholders::_1);
    std::cout << add5(9) << std::endl;
    auto multiply6 = std::bind(m1, 6, std::placeholders::_1);
    std::cout << multiply6(2) << std::endl;

    //绑定类成员函数
    Calculator c1;
    auto sub15 = std::bind(&Calculator::subtract, &c1, 15, std::placeholders::_1);
    std::cout << sub15(4) << std::endl;
    auto disoperation1 = std::bind(&Calculator::displayoperation, &c1, "zzx", 5);
    auto disoperation2 = std::bind(&Calculator::displayoperation, &c1, std::placeholders::_1, 5);
    auto disoperation3 = std::bind(&Calculator::displayoperation, &c1, "zzx", std::placeholders::_1);
    disoperation1();
    disoperation2("zt");
    disoperation3(9);

    //绑定静态成员函数
    auto logfunc = std::bind(&Logger::Log, std::placeholders::_1);//静态成员函数实例化不需要具体对象
    logfunc("ZZX666");

    //function存储混合可调用对象
    std::vector<std::function<void()>> operations;
    operations.emplace_back([&]() { std::cout << "Lambda Operation" << std::endl; });
    operations.emplace_back(std::bind(&Calculator::displayoperation, &c1, "Multiply", 30));
    operations.emplace_back([&]() { std::cout << "Add5(10): " << add5(10) << std::endl; });
    operations.emplace_back([&]() { Logger::Log("Lambda-based log message."); });
    /*添加不同的操作到容器中，事实上，添加的都是function对象，只是每个function对象对应的操作不同 */

// 执行所有操作
    for (auto& op : operations) {
        op();
        //打印Lambda Operation
        //c1.displayoperation("Multiply",30);
        //add5(10);
        //打印 Log: Lambda-based log message.
    }
    return 0;
}