#include <iostream>
using namespace std;
#include <string>

//全局函数类外实现:让编译器知道Person类存在

template<class T1, class T2>
class Person;
//这个实现也要放到前面来
template<class T1, class T2>
void printPerson1(Person<T1, T2> p) {
    cout << "1" << p.age << endl;
}

template <class T1, class T2>
class Person {
public:

    //全局函数 类内实现
    friend void printPerson(Person<T1, T2> p) {
        cout << p.name << " " << p.age << endl;
    }
    //全局函数 类外实现
        //加空模板参数列表
        //全局函数类外实现需要让编译器提前知道此函数存在
    friend void printPerson1<>(Person<T1, T2> p);
    Person(T1 name, T2 age);
private:
    T1 name;
    T2 age;
};


template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
    this->name = name;
    this->age = age;
}


void test() {
    Person p1("nike", 20);
    printPerson(p1);
    printPerson1(p1);
}
int main() {
    test();
}