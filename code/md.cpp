#include <iostream>
using namespace std;
#include <string>

class Animal {
public:
    Animal() {
        cout << "Animal构造" << endl;
    }
    //virtual ~Animal() {
    //    cout << "Animal虚析构" << endl;
    //}
    virtual ~Animal() = 0;
    virtual void speak() = 0;
    string* m_name;
};

Animal::~Animal() {
    cout << "Animal纯虚析构" << endl;
}

class Cat :public Animal {
public:
    void speak() {
        cout << "Cat构造" << endl;
        cout << *m_name << "在叫" << endl;
    }
    Cat(string name) {
        m_name = new string(name);
    }
    ~Cat() {
        if (m_name != nullptr) {
            cout << "Cat析构" << endl;
            delete m_name;
            m_name = nullptr;
        }
    }
    string* m_name;
};

void test() {
    Animal* a1 = new Cat("tom");
    a1->speak();
    delete a1;
    //父类指针在析构时，不会调用子类中的析构函数，导致子类如果有堆区属性，未被释放，导致内存泄漏
    //改成虚析构解决，这样就会走子类中的析构函数 virtual ~Animal(){}
    //当然也有纯虚析构 virtual ~Animal() = 0;(子类中记得重写)
    //但由于此代码中，父类析构函数也运行到了，因此必须要有实现，在外部加Animal::~Animal(){代码实现}
    //纯虚析构类似一个声明，必须要有实现，在类外实现。有纯虚析构的也是抽象类
}
int main() {
    test();
    return 0;
}