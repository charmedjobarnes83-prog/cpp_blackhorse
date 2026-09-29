#include <queue>
#include <string>
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

class Transform {
public:
    int operator()(int val) {
        return val;
    }
};
int Transform1(int val) {
    return val;
}
class myprint {
public:
    void operator()(int val) {
        cout << val << " ";
    }
};
void print1(int val) {
    cout << val << " ";
}
void test01()
{
    vector<int> v1;
    for (int i = 0;i < 10;i++) {
        v1.push_back(i);
    }
    vector<int> v2;
    vector<int> v3;
    v2.resize(v1.size());//目标容器需要提前开辟空间
    v3.resize(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), Transform());
    for_each(v2.begin(), v2.end(), myprint());
    transform(v1.begin(), v1.end(), v3.begin(), Transform1);
    for_each(v3.begin(), v3.end(), myprint());
}
int main() {
    test01();
    return 0;
}