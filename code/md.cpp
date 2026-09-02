#include <iostream>
using namespace std;
#include <string>

class father{
    public:
        int a=10;
    protected:
        int b=20;
    private:
        int c=30;
};

class son1: public father{
    public:
        void show(){
            cout << "a = " << a << endl;
            cout << "b = " << b << endl;
            // cout << "c = " << c << endl; // private成员不能在子类中访问
        }
};
class son2: protected father{
    public:
        void show(){
            cout << "a = " << a << endl;
            cout << "b = " << b << endl;
            // cout << "c = " << c << endl; // private成员不能在子类中访问
        }
};
class son3: private father{
    public:
        void show(){
            cout << "a = " << a << endl;
            cout << "b = " << b << endl;
            // cout << "c = " << c << endl; // private成员不能在子类中访问
        }
};
void test(){
    son1 s1;
    son2 s2;
    son3 s3;
    s1.show();
    s2.show();
    s3.show();
}
void test1(){
    son1 s1;
    son2 s2;
    son3 s3;
    s1.a = 100; 
    //s1.b = 200;protected成员不能在类外访问
    //s2.a = 100;protected成员不能在类外访问
    //s2.b = 200;protected成员不能在类外访问
    //s3.a = 100;private成员不能在类外访问 
    //s3.b = 200;private成员不能在类外访问
    cout << "s1.a = " << s1.a << endl;

}
int main(){
    test();
    test1();
    
    return 0;
}