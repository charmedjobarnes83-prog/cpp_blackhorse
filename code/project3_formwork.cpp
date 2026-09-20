#include <iostream>
#include <string>
using namespace std;
#include <MyArray.hpp>

void printarray(MyArray<int>& arr) {
    for (int i = 0;i < arr.getsize();i++) {
        cout << arr[i];
    }
}
void test() {
    MyArray <int>arr1(5);
    /*MyArray <int>arr3(100);
    arr3 = arr1;*/

    for (int i = 0;i < 5;i++) {
        arr1.push_back(i);
    }
    MyArray <int>arr2(arr1);
    cout << "arr1:";
    printarray(arr1);
    cout << endl;
    cout << arr1.getcapacity() << endl;
    cout << arr1.getsize() << endl;
    printarray(arr2);
    cout << endl;
    arr2.pop_back();
    cout << arr2.getcapacity() << endl;
    cout << arr2.getsize() << endl;
    printarray(arr2);
    cout << endl;
}

//测试自定义数据类型
class Person {
public:
    Person() {};
    Person(string name, int age) {
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;

};
void printarray2(MyArray<Person>& arr) {
    for (int i = 0;i < arr.getsize();i++) {
        cout << arr[i].m_name << " " << arr[i].m_age << endl;
    }

}
void test2() {
    MyArray <Person>arr4(10);
    Person p1("mike", 20);
    Person p2("JACK", 55);
    Person p3("JOHN", 25);
    Person p4("danil", 10);
    Person p5("nik", 33);
    arr4.push_back(p1);
    arr4.push_back(p2);
    arr4.push_back(p3);
    arr4.push_back(p4);
    arr4.push_back(p5);
    printarray2(arr4);
    cout << arr4.getcapacity();
    cout << endl;
    cout << arr4.getsize();
    cout << endl;
}

int main() {
    test();//内置数据类型int类数组
    test2();//自定义数据类型Person类数组
}