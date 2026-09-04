#include <iostream>
using namespace std;
#include <string>
//1、包含头文件<fstream>
#include <fstream>

class Person {
public:
    char m_name[64];
    int m_age;
};

void test() {
    //2、创建流对象
    ifstream ifs;

    //3、打开文件 判断文件是否打开成功
    ifs.open("D:/94_binary.txt", ios::in | ios::binary);
    ///2和3可以合并 ofstream ofs("D:/94_binary.txt",ios::in|ios::binary);调用内部构造函数
    if (!ifs.is_open()) {
        cout << "打开失败" << endl;
        return;
    }
    //4、读文件
    Person p;
    ifs.read((char*)&p, sizeof(Person));
    cout << p.m_name << p.m_age << endl;

    //5、关闭文件
    ifs.close();
}

int main() {
    test();
}