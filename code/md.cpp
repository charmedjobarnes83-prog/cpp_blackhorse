#include <iostream>
using namespace std;
#include <string>

class mprint {
public:
    void operator()(string test) {//重载()运算符
        cout << test << endl;
    }
};//仿函数很灵活，没有固定写法

class Madd {
public:
    int operator()(int a, int b) {//重载()运算符
        return a + b;
    }
};//仿函数很灵活，没有固定写法

void m_print(string test) {
    cout << test << endl;
}

void test1() {
    mprint mprint;
    mprint("Hello World");//调用运算符重载，和函数调用非常像，又称仿函数
    m_print("Hello World");//函数
}

void test2() {
    Madd madd;
    cout << madd(1, 2) << endl;//仿函数

    //匿名函数对象。匿名对象：当前行执行完立即被释放
    cout << Madd()(3, 4) << endl;
}
int main() {
    test1();
    test2();
    return 0;
}