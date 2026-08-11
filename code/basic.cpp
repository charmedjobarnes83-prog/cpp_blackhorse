#include <iostream>
using namespace std;
#include <string>

//常量 两种方法
#define pai 3.14 //注意宏定义不需要加;
const int week = 7;

int main(){
    int a = 10;
    cout <<"a=" << a << endl;
    cout << pai << endl;
    cout << week << endl;
    cout << sizeof(short) <<endl;
    cout << sizeof(a) << endl;
    char str[] = "hello";
    string str1 = "hello";
    cout << str << endl;
    cout << str1 << endl;
    cin >> a;
    cout << "a=" << a << endl;
    int b = ++a;
    cout << "b=" << b << endl;//11
    int c = a++;
    cout << "c=" << c << endl;//11
    cout << "hello world";
    cout << "hello world" << endl;

    int a1 =100;
    do{
        int bai = a1/100;
        int shi = a1%100/10;
        int ge = a1%10;
        if(bai*bai*bai+shi*shi*shi+ge*ge*ge == a1){
            cout << a1 << endl;
        }
        a1++;
    }while(a1<1000);

    
    for(int i = 1 ;i<10;i++){
        for(int j = 1;j<=i;j++){
            cout << i << "*" << j << "=" << i*j << "\t";//转义符\t优先级高于""
        }
        cout << endl;
    }
    return 0;
}