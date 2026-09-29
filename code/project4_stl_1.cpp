#include <iostream>
using namespace std;
#include <string>
#include <deque>
#include <vector>
#include <algorithm>

class Person {
public:
    Person(int score, string name) {
        this->m_name = name;
        this->m_averagescore = score;
        cout << "请输入第评委分数" << endl;
        for (int i = 0;i < 5;i++) {
            cin >> score;
            d.push_back(score);
        }
        sort(d.begin(), d.end());
        d.pop_back();
        d.pop_front();
        int sum = 0;
        for (deque<int>::iterator it = d.begin();it < d.end();it++) {
            sum += *it;
        }
        m_averagescore = sum / d.size();
    }
    int m_averagescore;
    int score;
    string m_name;
    deque<int> d;
};

void myprint(deque<int> d) {
    for (deque<int>::iterator it = d.begin();it < d.end();it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void test() {
    Person p1(0, "a"), p2(0, "b"), p3(0, "c"), p4(0, "d"), p5(0, "e");
    vector<Person> v1;
    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);
    v1.push_back(p4);
    v1.push_back(p5);
    for (vector<Person>::iterator it = v1.begin(); it < v1.end();it++) {
        cout << (*it).m_name << " " << (*it).m_averagescore << endl;
    }
}
int main() {
    test();
}