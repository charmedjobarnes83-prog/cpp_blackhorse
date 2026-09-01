#include <iostream>
using namespace std;
#include <string>

class Person {
public:
    Person(int age){
        m_age = new int(age);//把传入的age数据，开辟到堆区，用指针m_age维护此堆区数据
        //因为new返回的是一个地址，m_age是一个指针变量，所以可以直接接收new返回的地址
    }
    int *m_age;//年龄的指针数据
}; 