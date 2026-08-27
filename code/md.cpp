#include <iostream>
using namespace std;
#include <string>

class person{
public:
    void showperson()const{
        //m_a = 10;等价this->age=100;this指针不可以修改指针的指向
        this->m_b = 100;//定义时加mutable即可修改
        cout<<"1"<<endl;
    }
    void func(){
        
    }
    int m_a=0;
    mutable int m_b=0;
};
void test1(){
    person p;
    p.showperson();
}
//常对象
void test2(){
    const person p1;
    //p1.m_a = 200;常对象不能修改普通的成员变量
    p1.m_b = 200;
    
    p1.showperson();
    //p1.func();常对象只能调用常函数
}
int main(){
    test1();
    test2();
}