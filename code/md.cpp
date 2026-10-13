#include <queue>
#include <string>
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <memory>

class Cat {
public:
    string name;
	shared_ptr<Cat> m_friend;
    Cat(string n){ 
		name = move(n);//写成name=n也行
		cout << "构造 " << name << endl; 
	}
    ~Cat() { cout << "析构 " << name << endl; }
    Cat& setName(string n) { name = move(n); return *this; }  // 返回自身引用，支持链式
	void set_friend(shared_ptr<Cat> c){
		m_friend = c;
	}
};
 

void test01()
{
   shared_ptr<int> s1 = make_shared<int>(10);
   cout << "shared count: " << s1.use_count() << endl;
   weak_ptr<int> w1(s1);
   cout << "weak count: " << w1.use_count() << endl;//weak_ptr可以调用use_count()但不能+1
   cout << "shared count: " << s1.use_count() << endl;
   //w1->show(); weak_ptr 不能用->
   shared_ptr<int> s2 = w1.lock();//通过lock()转换类型，且use_count+1，意味着weak_ptr已转化为shared_ptr
   cout << "shared count: " << s2.use_count() << endl;

   shared_ptr<Cat> c3 = make_shared<Cat>("c3");
   shared_ptr<Cat> c4 = make_shared<Cat>("c4");
   c3->set_friend(c4);
   c4->set_friend(c3);
}
int main() {
    test01();
    return 0;
}

  