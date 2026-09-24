#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>//标准算法头文件

void test() {
    vector<int> v1;
    v1.reserve(10000);
    int num = 0;
    int* p = nullptr;
    for (int i = 0;i < 10000;i++) {
        v1.push_back(i);
        if (p != &v1[0]) {
            p = &v1[0];
            num++;
        }
    }
    cout << num;
    /*vector<int> v1;
    int num = 0;
    int* p = nullptr;
    for (int i = 0;i < 10000;i++) {
        v1.push_back(i);
        if (p != &v1[0]) {
            p = &v1[0];
            num++;
        }
    }
    cout << num;
    */
}
int main() {
    test();
}