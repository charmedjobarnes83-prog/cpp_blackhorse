#include <iostream>
using namespace std;
#include <string>

class animal {
public:
    int age;
};

class sheep :virtual public animal {

};
class tuo :virtual public animal {

};

class sheeptuo :public sheep, public tuo {

};
void test() {
    sheeptuo s1;
    s1.sheep::age = 10;
    s1.tuo::age = 20;
    cout << s1.sheep::age << endl;
    cout << s1.tuo::age << endl;
    cout << s1.age << endl;//虚继承特有

}
int main() {
    test();
}