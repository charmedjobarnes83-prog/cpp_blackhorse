#include <iostream>
using namespace std;
#include <string>

//常量 两种方法
#define pai 3.14 //注意宏定义不需要加;
const int week = 7;

int main() {
    int a = 10;
    cout << "a=" << a << endl;
    cout << pai << endl;
    cout << week << endl;
    cout << sizeof(short) << endl;
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

    int a1 = 100;
    do {
        int bai = a1 / 100;
        int shi = a1 % 100 / 10;
        int ge = a1 % 10;
        if (bai * bai * bai + shi * shi * shi + ge * ge * ge == a1) {
            cout << a1 << endl;
        }
        a1++;
    } while (a1 < 1000);


    for (int i = 1;i < 10;i++) {
        for (int j = 1;j <= i;j++) {
            cout << i << "*" << j << "=" << i * j << "\t";//转义符\t优先级高于""
        }
        cout << endl;
    }

    for (int i = 0;i < 10;i++) {
        for (int j = 0;j < 10;j++) {
            if (j == 5) {
                break;//break会打印5个0 continue会打印9个0
            }
            cout << i << endl;
        }
    }

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

    int arr2[5]={1,2,3,4,5};
    int end2 = sizeof(arr2)/sizeof(arr2[0]);
    int end1 = end2;
    int num2;
    for(int i=0;i<(end1);i++){
        if(end2>i){ 
            num2 = arr2[i];
            arr2[i] = arr2[end2-1];
            arr2[end2-1] = num2;
            end2--;
        }
    }
    for(int i=0;i<=(end1-1);i++){
    cout<< arr2[i] << endl;
    }


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

    int arr0[] = {5,0,6,3,7,1,8,9};
    len = sizeof(arr0)/sizeof(arr0[0]);
    int max;
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-i-1;j++){
            if (arr0[j]>arr0[j+1]){
                max = arr0[j];
                arr0[j] = arr0[j+1];
                arr0[j+1] = max;
            }
        }
    }
    for(int i=0;i<len;i++){
        cout << arr0[i];
    }
    return 0;
}