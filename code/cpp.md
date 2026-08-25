- [数据类型](#数据类型)
- [运算符](#运算符)
- [程序结构](#程序结构)
- [数组](#数组)
- [函数](#函数)
- [指针](#指针)
- [结构体](#结构体)
- [内存](#内存)
  - [new](#new)
- [引用(给变量起别名)](#引用给变量起别名)
- [函数高级](#函数高级)
  - [函数的默认参数](#函数的默认参数)
  - [函数的占位参数](#函数的占位参数)
  - [函数重载](#函数重载)
- [类\&对象](#类对象)
  - [封装](#封装)
  - [对象](#对象)

```text
生成目录 ctrl+shift+p Markdown: Create Table of Contents
更新目录 自动更新 或手动更新 ctrl+shift+p Markdown: Update Table of Contents
```

## 数据类型
内存占用
```cpp
short 2字节
int   4字节
long  win为4字节 linux为4字节(32位)和8字节(64位)
long long   8字节
float 4字节
double 8字节
char 1字节
```
sizeof()
```cpp
int a = 10;
cout << sizof(short) <<endl;
cout << sizeof(a) << endl;
```
定义
```cpp
float c = 1.11;//默认为double，此操作将c转为float
float d = 1.11f;

//科学计数法
float f1 = 3e2;//3*10^2
float f2 = 3e-3;//3*10^-3

char ch = 'a';//只能有一个字符，且只能用单引号
//字符型变量char 并不是把字符本身放到内存中存储，而是将对应的ASCII编码放入到存储单元 a-97 A-65
int ass = int(ch);//97

//字符串
char str[] = "hello";
//或
#include <string>
string str1 = "hello";

//布尔
bool flag = true;
//打印输出为1
cout <<flag << endl;
```
数据输入
```cpp
int a = 0;
cin >> a;
//输入bool型时，只接受数字，不接收true/false  
```
\n换行 \t水平制表 \\转义

## 运算符
前置++
```cpp
//先+1，后运算表达式
int a = 10;
int b = ++a;
cout << b << endl;//b = 11
```
后置++
```cpp
//先进行表达式运算，后+1
int a = 10;
int b = a++;
cout << b << endl;//b = 10
```

## 程序结构
 if
 ```cpp
if(a>b){
    cout << a;
}
 ```
 三目运算符
 ```cpp
int a = 10;
int b = 20;
int c = 0;
c = a>b ? a:b;
//a>b成立则c=a a>b不成立则c=b
 ```
 switch
 ```cpp
switch(){
    case 1:a++;break;
    case 2:a--;break;
    default:a=b;break;
}
//不加break的话，倘若case为2，会运行a-- 和 a=b。
//switch相比if 执行效率高
 ``` 
 while和do_while
```cpp
int num = 0; 
//do_while先执行一次循环语句再判断循环条件 且dowhile的while后要加一个;
do{
    cout << num << endl;
    num++;
}while(num<10);
//while
while(num<10){
    cout << num << endl;
    num++;
}
```
水仙花数
```cpp
# 1^3+5^3+3^3=153
#include <iostream>
using namespace std;

int main(){
    int a =100;
    do{
        int bai = a/100;
        int shi = a%100/10;// a/10%10
        int ge = a&10;
        if(bai*bai*bai+shi*shi*shi+ge*ge*ge == a){
            cout << a << endl;
        }
        a++;
    }while(a<1000);
}
```
for
```cpp
for(int i = 0;i<100;i++){
    
}
```
9x9
```cpp
for(int i = 1 ;i<10;i++){
    for(int j = 1;j<=i;j++){
        //cout <<i "*" j = i*j >> endl;
        cout <<i << " * " << j << " = " << i*j << endl;
    }
    cout << endl;
}
```
break 直接结束此层循环
```cpp
for (int i=0;i<100;i++){
    if(i=10){
        break;
    }
}
```
continue 跳过此次循环的剩余代码，进入下一轮循环
```cpp
for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
        if(j=5){
            continue;
        }
        cout <<i << endl;
    }
}
```
goto
```cpp
cout << "1"<< endl;
cout << "2"<< endl;
goto FLAG;
cout << "3"<< endl;
cout << "4"<< endl;
FLAG:
cout << "5"<< endl;
```
## 数组
定义
```cpp
int arr1[];
int arr2[10]={};
int arr3[]={1,2,3,4,5};
```
sizeof
```cpp
sizeof(arr1);//统计整个数组在内存中的长度
sizeof(arr1[0]);//首个元素的内存占用长度
sizeof(arr1)/sizeof(arr1[0]);//二者结合可知数组长度
cout<<arr1 << endl;//打印出数组的首地址
```
元素逆置
```cpp
//法一
int arr1[5] = {1,2,3,4,5};
int end = sizeof(arr1)/sizeof(arr1[0]);
int num1;
for(int i=0;i<(end/2);i++){
    num1 = arr1[i];
    arr1[i]=arr1[end-1-i];
    arr1[end-1-i]=num1;
}
for(int i=0;i<=(end-1);i++){
    cout<< arr1[i] << endl;
}

//法二
int arr2[5]={1,2,3,4,5}
int end2 = sizeof(arr1)/sizeof(arr1[0]);
int num2;
for(int i =0;i<end2;i++){
    num2 = arr2[i];
    arr2[i] = arr2[end2-1];
    arr2[end2-1] = num2;
    end2--;
}
for(int i=0;i<=(end2-1);i++){
    cout<< arr2[i] << endl;
}

//法三
int arr3[5] = {1,2,3,4,5};
int end3 = sizeof(arr3)/sizeof(arr3[0]) - 1;
int num3;
int len = sizeof(arr1)/sizeof(arr1[0]);
int start3 = 0;
while(start3<end3){
    num3 = arr3[start3];
    arr3[start3] = arr3[end3];
    arr3[end3] = num3;
    end3--;
    start3++;
}
for(int i=0;i<len;i++){
    cout << arr3[i];
}
```
冒泡排序

![截图](./picture/1.png)

```text
排序总轮数 = 元素个数 - 1
每轮对比次数 = 元素个数 - 排序轮数 - 1
```
```cpp
int arr0[] = {5,0,6,3,7,1,8,9};
len = sizeof(arr0)/sizeof(arr0[0]);
int max;
for(int i=0;i<len-1;i++0){
    for(int j=0;j<len-i-1;j++){
        if (arr0[j]>arr0[j+1]){
            max = arr0[j];
            arr0[j] = arr0[j+1];
            arr0[j+1] = max;
        }
    }
}
for(int i=0;i<len;i++){
    cout << arro[i];
}
```
二维数组
```cpp
 int arr[2][3] = {{1,2,3},{4,5,6}};//{1,2,3,4,5,6}也可以
 int arr1[][3] = {1,2,3,4,5,6,7,8,9};//行数可以省略，列数不可以省略
//遍历
for(int i=0;i<2;i++){ 
    for(int j=0;j<3;j++){
        cout << arr[i][j] << endl;
    }
}   
//取某个元素的首地址时需要加取址符 & 
cout << (int)&arr[0][0] << endl;
```
## 函数
程序从上往下读，如果函数定义在调用之后，那么需要提前声明
```cpp
#include <iostream>
using namespace std;

int max();

int main(){
    return 0;
}
int max(){
    return 0;
}
```
分文件编写函数
```text
建一个.h文件用于写声明
建一个cpp文件用于写定义  顶部引用头文件#include "swap.h"
```
## 指针
定义
```cpp
int a = 10;
int * p = &a; //32位win占4字节   64位win占8字节 不管是什么数据类型(int/float/double)
cout << p << " " << &a << endl;
```
解引用 *p -> p指向的数值
```cpp
int a = 100;
int * p = &a;
*p = 1000;
cout << a <<" " << *p << endl; 
```
空指针
```text
初始化指针变量
且空指针指向的内存无法访问
内存编号0~255为系统占用内存，不允许用户访问
```
```cpp
int *p = NULL;
```
野指针
```text
指针变量指向非法的内存空间，访问会出错
```
const
```cpp
//常量指针(修饰指针)  指针的指向可以更改，但指针指向的值不可更改
int a = 10;
int b = 20;
const int *p = &a;
p = &b;
//*p = 30;错误

//指针常量(修饰常量) 指针指向不可改，指向的值可以改
int a = 10;
int b = 20;
int * const p = &a;
*p = 30;
//p = &b;错误

//const既修饰指针也修饰常量   两个都不可以改
int a = 10;
int b = 20;
const int * const p = &a;
//p = &b;错误
//*p = 30;错误
```
指针访问数组元素
```cpp
int arr[10] = {1,2,3,4,5,6,7,8,9,10};
int *p = arr;
cout << "第一个元素为：" << arr[0] << endl;//1
cout << "利用指针访问第一个元素" << *p << endl;//1
p++;//让指针向后偏移四个字节(智能识别步长，若为char *p 则p++代表偏移一个字节)
cout << "利用指针访问第二个元素：" << *p << endl;//2
```  
指针遍历数组
```cpp
int arr[10] = {1,2,3,4,5,6,7,8,9,10};
int *p = arr;
for(int i = 0;i<10;i++){
    cout << *p << endl;
    p++;
}
```
指针和函数
```cpp
//值传递不会改变实参数据
//地址传递可以实现改变实参数据
void swap(int *p1,int *p2){
    int temp = *p1;
    *p1 = *p2; 
    *p2 = temp;
    cout << *p1 << *p2 << endl;// 20 10
}
int main(){
    int a = 10;
    int b = 20;
    swap(&a,&b);
    cout << a << b << endl;//20 10
}
```
## 结构体
定义
```cpp
#include <iostream>
using namespace std;
#include <string> //cout << name

struct Student{
    string name;
    int age;
    int score;
}; // ;不要漏

int main(){
    struct Student s1;//创建结构体对象时，struct可以省略，即Student s1
    s1.name = "mike";
    s1.age = 11;
    s1.score = 100;
    cout << "name" << s1.name << "age" << s1.age << "score" << s1.score;
    
    struct Student s2 = {"jack",12,200};

} 
``
结构体数组
```cpp
struct Student{
    string name;
    int age;
    int score;
};

int main(){
    struct Student stuArray[]={
        {"mike",10,200},
        {"jack",21,130},
        {"lucy",30,90}
    };
    stuArray[2].name = "niko";

}
```
结构体指针
```cpp
struct Student{
    string name;
    int age;
    int score;
};

int main(){
    Student s = {"mike",11,100};
    Student *p = &s;//s是student型变量
    cout << p->name 
}
```
结构体嵌套结构体
```cpp
#include <iostream>
using namespace std;
#include <string> //cout << name

struct Student{
    int score;
    int age;
    string name;
};
struct Teacher{
    string name;
    int age;
    int id;
    Student stu;
};

int main(){
    Teacher t;
    t.id = 1001;
    t.age = 20;
    t.name = "mike";
    t.stu.name = "jack";
    t.stu.age = 10;
    t.stu.score = 100;
    cout << "teacher name:" << t.name << ", age:" << t.age << ", id:" << t.id << endl;
    cout << "stu.name:" << t.stu.name << ", stu.age:" << t.stu.age << ", stu.score:" << t.stu.score << endl;
}
```
结构体作为参数
```cpp
//值传递
void test1(struct student s){
    cout << s.name;
}

//地址传递
void test2(struct student *p){
    cout << p->name;
}

int main(){
    Student s1 = {"mike",11,200};
    test1(s1);
    test2(&s1);
}
```
const应用于结构体(常量指针)
```cpp
void test1(const Student *s){
      
}
//用常量指针每次只传递一个指针，仅4字节，而值传递则会复制整个结构体的数据过去。相比之下速度更快且能防止栈溢出
//相比于指针，常量指针不会改变实参的值
```
随机数
```cpp
#include <ctime>

srand((unsigned int)time(NULL));
int random = rand()%61+40//rand()%61 表0到60的随机数
```
## 内存
cpp程序运行时内存分区
```text
代码区 : 存放函数体的二进制代码  (共享 只读)   
全局区 : 存放全局变量、静态变量、常量
栈区 : 由编译器自动分配释放，存放函数的参数值，局部变量等 (不要返回局部变量的地址)
堆区 : 由程序员分配释放，若程序员不操作，程序结束时由操作系统回收
```
不要返回局部变量的地址
```cpp
int * func(){
    int a = 10;
    return &a;
}
int main(){
    int *p = func();
    cout << *p << endl;//第一次可以打印出正确的数字10
    cout << *p << endl;//第二次数据不再保留
}
```
利用new关键字，可以将数据开辟到堆区->可以返回局部变量的地址
```cpp
int * func(){
    int *p = new int(10);
    //new会返回开辟出的内存的地址(即返回new的类型的指针)，10代表将此数据赋初值
    return p; 
}
int main(){
    int *p = func();
    cout  << *p << endl;
    cout  << *p << endl;//均能成功返回数据10

}
```
### new
new的基本语法(new什么数据，就会返回个什么类型的指针)
```cpp
int * func(){
    int *p = new int(10);
    return p; 
}
void test1(){
    int *p = func();
    cout  << *p << endl;
    cout  << *p << endl;
    //堆区的数据由程序员管理开辟，程序员管理释放
    //释放堆区数据用delete
    delete p;
    cout  << *p << endl;//报错，内存已释放，无法访问
}
void test2(){
    //在堆区中new开辟数组
    new int[10];//10代表有10个元素，(10)代表赋初值10
    for(int i=0;i<10;i++){
        arr[i] = i+100;
    }
    for(int i=0;i<10;i++){
       cout << arr[i] <<endl;//可正常输出
    } 
    //释放堆区数组的内存,加上中括号
    delete[] arr;
    for(int i=0;i<10;i++){
       cout << arr[i] <<endl;//内存已释放，无法访问
    }

}
int main(){
    test1();
    test2();
}
```
## 引用(给变量起别名)
数据类型 &别名 = 原名
```cpp
int &b = a;
b = 20;
cout << a << endl;//输出20
//a，b操纵的是同一片内存
```
注意事项
```cpp
//引用必须要初始化
int &b;//错误示范
int &b = a;

//引用一旦初始化便不可更改
int a = 10;
int &b = a;
int c = 20;
&b = c;//错误示范
b = c;//仅赋值操作而非更改引用
```
引用做函数参数
```cpp
//形参修饰实参有两种方法，一种是地址传递，一种是引用传递
void swap1(int &a,int &b){//与swap1(int *a,int *b) 做区分
    //此处的ab是实参ab的别名，实际上就是指向实参ab的地址
    int temp = a;
    a = b;
    b = temp;    
}
int  main(){
    int a = 10;
    int b = 20;
    swap1(a,b);
    cout << a << endl;
    cout << b << endl；//成功交换
}
```
引用做函数返回值
```cpp
//不要返回局部变量的引用(和不要返回局部变量的地址原理一样，即函数运行完就释放局部变量的内存)
int& test1(){
    int a = 10;
    return a;
}  
int& test2(){
    static int a = 10;//静态变量，存在全局区，全局区上的数据等程序结束后再释放
    return a;
}
int main(){
    a1 = test1();
    cout << a1 << endl;//10
    cout << a1 << endl;//无结果
    a2 = test2();
    cout << a2 << endl;//20
    cout << a2 << endl;//20
    //函数的调用可以作为左值
    a3 = test2() = 1000;
    cout << a3 << endl;//1000
    cout << a3 << endl;//1000
} 
```
引用本质 相当于一个常量指针
```cpp
    int a =10;
    
    int * const ref = &a;
    等价
    int& ref = a;
```
const修饰引用--防止误操作
```cpp
void  showValue(int &val){
    val = 1000;
    cout << val << ednl;
}
void showValue1(const int &val){//加上const 对val的修改操作便是违法行为
    cout <<  val << ednl;
}
int main(){
    int a = 100;
    showValue(a);//函数内修改val，指向同一片内存，a也被修改为1000
    showValue1(a);
    cout<< a<< endl;
}
```
```cpp
int main(){
    int& ref = 10;//编译错误
    const int& ref = 10;//编译器优化代码，int temp = 10;  const  int& ref = temp;
}
```
## 函数高级
### 函数的默认参数
默认参数必须放在最后。如果自己传入数据，那么就用自己的数据，如果没有传入数据，那么就用默认值。
```cpp
如 int func(int a,int b = 1,int c){} //错误
   int func(int a ,in b = 1, int c = 2){} //正确
```
```cpp
int sum(int a,int b,int c=1){
    return a+b+c;
}
int main(){
    int a = 1;
    int b = 2;
    int c = 3;
    sum = sum(a,b,c);  //结果为6
    sum1 = sum(a,b);  //结果为4
}
``` 
如果函数声明有默认参数，函数实现就不能有默认参数(二选一)
```cpp
int func(int a=10,int b=20);
int func(int a=10,int b=20){//报错，重新定义了默认参数
    return a+b;
}
```
### 函数的占位参数
占位了必须传对应的数据，但传过来的数据暂时用不到
```cpp
void func(int a,int){
    pass;
}
int main(){
    func(10,20);
}
```
占位参数可以有默认参数
```cpp
void func(int a,int = 20){
    pass;
}
int main(){
    func(10);
}
```
### 函数重载
函数名可以相同，以提高复用性
```text
条件 均要满足
一:同一个作用域下
二:函数名称相同
三:函数参数类型不同，或个数不同，或顺序不同
```
```cpp
void func(){
    cout << "1" << endl;
}
void func(int a){
    cout << "2" << endl;
}
int main(){
    func();
    func(1);
}
```
函数的返回值不可以作为函数重载的条件
```cpp
//错误示范
void func(){
    cout << "1" << endl;
}
int func(){//仅返回值不同不满足条件
    cout << "2" << endl;
}
int main(){
    func();//1
    func(1);//2
}
```
引用作为重载的条件
```cpp
void func(int &a){
    cout << "1" << endl;
}
void func(const int &a){
    cout << "2" << endl;
}
int main(){
    int a =10;
    func(a);//a是变量,打印1
    func(10);//打印2
}
```
函数重载遇到默认参数
```cpp
void func(int a,int b=10){
     cout << "1" << endl;
}
void func(int a){
    cout << "2" << endl;
}
int main(){
    func(10);//这样调用错误，两个func都能调用
    //故避免这种情况发生
    func(10,20);//可成功调用，意味着第二个func()调用不了
}
```
## 类&对象
### 封装
属性和行为作为整体，即变量和函数
```text
类中的属性和行为，统一称为成员
属性：成员属性/成员变量
行为：成员函数/成员方法
```
```cpp
class Circle {

public:

    int m_r;
    
    double calculate1() {
        return 2 * (3.14) * m_r;
    }
};

int main() {
    Circle c1;
    c1.m_r = 10;
    cout << "周长" << c1.calculate1() << endl;
}
```
```cpp
class student {

public:
    string name;
    int id;

    void set() {
        cin >> name;//cin << this->name
        cin >> id;//cin << this->id
    }
    string printname() {
        return name;
    }
    int printid() {
        return id;
    }

};


int main() {
    student s1;
    s1.set();
    cout << s1.printid() << endl;
    cout << s1.printname() << endl;
}
```
访问权限
```text
public 公共--成员 类内可以访问，类外也可以访问
private 私有--成员 类内可以访问，类外不可以访问(子类不可以访问父类中的private内容)
protected 保护--成员 类内可以访问，类外不可以访问(子类可以访问父类中的protected内容)
```
class与struct区别
```text
默认的访问权限不同

struct中默认为public
class 中默认为private
```
在开发中，一般将成员属性设为私有，而成员函数设为公有
```text
优点1：将所有成员属性设为私有，可以自己控制读写权限(自己设置读写的接口)
优点2：对于写权限，可以检测数据的有效性
```
```cpp
class student {

private:
    string my_name;
    int my_id = 10;

public:
    void setname(string name) {
        my_name = name;
    }
    string printname() {
        return my_name;
    }
    int printid() {
        return my_id;
    }

};


int main() {
    student s1;
    s1.setname("mike");//用了公有的写接口
    //s1.my_id = 30;//报错，无法访问私有变量，即只读不写
    //cout << s1.my_id << endl;//没用公有的读接口，无法访问
    cout << s1.printname() << endl;//用了公有的读接口
    cout << s1.printid() << endl;//用了公有的读接口
}
```
封装案例

 [package_test.cpp 源码](./package_test.cpp)

 [package_test1.cpp 源码](./package_test1.cpp)

 ### 对象
 构造函数
 ```text
类名(){}
没有返回值也不写void
函数名称与类名相同
构造函数可以有参数因此可以发生重载
程序在调用对象时会自动调用构造，无需手动调用，且只会调用一次
 ```
 析构函数
 ```text
~类名(){}
没有返回值也不写void
函数名称与类名相同，在名称前加上~
构造函数无参数，因此不可以重载
程序在对象销毁前会自动调用析构，无需手动调用，且只会调用一次
```
