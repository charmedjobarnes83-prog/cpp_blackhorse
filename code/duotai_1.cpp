#include <iostream>
using namespace std;
#include <string>
//多态实现计算器功能(增加功能通过扩展实现，而非修改)

class basicCalculator {
public:
    int m_a;
    int m_b;
    virtual int getResult() {
        return 0;
    }
};
//加法类
class addCalculator :public basicCalculator {
public:
    virtual int getResult() {
        return m_a + m_b;
    }
};
//减法类
class subCalculator :public basicCalculator {
public:
    virtual int getResult() {
        return m_a - m_b;
    }
};
//乘法类
class mulCalculator :public basicCalculator {
public:
    virtual int getResult() {
        return m_a * m_b;
    }
};

void test() {
    //多态使用条件：父类指针或引用指向子类对象
    //Q1:用指针和引用有什么区别？
    //Q2:和basicCalculator & b2 = new addCalculator;有什么区别(这是个错误的写法)

     //A1:指针
    basicCalculator* b1 = new addCalculator;
    b1->m_a = 10;
    b1->m_b = 20;
    cout << b1->getResult() << endl;
    delete b1;//将堆区new出来的数据销毁
    //A2:后面跟一个new必须采用指针的形式，因为new出来得到的结果是新对象的地址。

    //A1:引用
    addCalculator a2;
    basicCalculator& b4 = a2;
    b4.m_a = 10;
    b4.m_b = 20;
    cout << b4.getResult() << endl;

    subCalculator s1;
    mulCalculator m1;
    basicCalculator& b2 = s1;
    basicCalculator& b3 = m1;
    b2.m_a = 10;
    b2.m_b = 1;
    b3.m_a = 2;
    b3.m_b = 4;
    cout << b2.getResult() << endl;
    cout << b3.getResult() << endl;

    b1 = new subCalculator;//b1可重复使用
    b1->m_a = 10;
    b1->m_b = 1;
    cout << b1->getResult() << endl;
    delete b1;

    b1 = new mulCalculator;
    b1->m_a = 2;
    b1->m_b = 4;
    cout << b1->getResult() << endl;
    delete b1;

}
int main() {
    test();
    return 0;
}