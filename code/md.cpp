#include <iostream>
using namespace std;
#include <string>

class Person{
public:
    Person(){
        cout<<"1构造函数调用"<<endl;
    }
    ~Person(){
        cout<<"2析构函数调用"<<endl;
    }
};
int main(){
    Person p;
}