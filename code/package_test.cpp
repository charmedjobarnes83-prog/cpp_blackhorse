#include <iostream>
using namespace std;
#include <string>

class cube {
public:
    void set_l(int l) {
        m_l = l;
    }
    int get_l() {
        return m_l;
    }
    void set_w(int w) {
        m_w = w;
    }
    int get_w() {
        return m_w;
    }
    void set_h(int h) {
        m_h = h;
    }
    int get_h() {
        return m_h;
    }
    int calculateS() {
        return m_l * m_w * 2 + m_l * m_h * 2 + m_w * m_h * 2;
    }
    int calculateV() {
        return m_l * m_h * m_w;
    }
    bool isSame(cube& c) {
        if (m_h == c.m_h && m_l == c.m_l && m_w == c.m_w) {
            return true;
        }
        return false;
    }
private:
    int m_l;
    int m_w;
    int m_h;
};
int main() {
    cube c1;
    c1.set_l(2);
    c1.set_h(5);
    c1.set_w(5);
    cout << "S:" << c1.calculateS() << endl;
    cout << "V:" << c1.calculateV() << endl;
    cube c2;
    c2.set_l(5);
    c2.set_h(5);
    c2.set_w(5);
    cout << c1.isSame(c2);
}