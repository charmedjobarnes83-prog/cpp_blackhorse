#include <iostream>
using namespace std;
#include <string> //cout << name

struct Student{
    string name;
    int age;
    int score;
};

int main(){
    struct Student s1;//创建结构体对象时，struct可以省略，即Student s1
    s1.name = "mike";
    s1.age = 11;
    s1.score = 100;
    Student *p = &s1;
    cout << "name: " << s1.name << ", age: " << s1.age << ", score: " << s1.score << endl;
    
    struct Student s2 = {"jack",12,200};
    cout << "name: " << s2.name << ", age: " << s2.age << ", score: " << s2.score << endl;

    cout << p->name << endl; //通过指针访问结构体成员
} 