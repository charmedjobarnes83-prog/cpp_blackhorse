#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>//标准算法头文件


void test() {
    string s1 = "我";
    cout << s1 << " 1" << endl;
    s1 += "是";
    cout << s1 << " 2" << endl;
    s1 += 'b';
    cout << s1 << " 3" << endl;
    string s2 = "的";
    s1 += s2;
    cout << s1 << " 4" << endl;
    s1.append("编");
    cout << s1 << " 5" << endl;
    s1.append("maker", 3);
    cout << s1 << " 6" << endl;
    s1.append(s2);
    cout << s1 << " 7" << endl;
    string s3 = "idsuper";
    s1.append(s3, 2, 4);
    cout << s1 << " 8" << endl;
}
int main() {
    test();
}