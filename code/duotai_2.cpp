#include <iostream>
#include <string>
using namespace std;

class AbstractDrink {
public:
    virtual void boil() = 0;
    virtual void brew() = 0;
    virtual void pull() = 0;

    void makeDrink() {
        boil();
        brew();
        pull();

    }

};
class coffee :public AbstractDrink {
    void boil() {
        cout << "烧开水" << " ";
    }
    void brew() {
        cout << "放咖啡豆" << " ";
    }
    void pull() {
        cout << "倒热水" << endl;
    }
};

class tea :public AbstractDrink {
    void boil() {
        cout << "烧开水" << " ";
    }
    void brew() {
        cout << "放茶叶" << "   ";
    }
    void pull() {
        cout << "倒热水" << endl;
    }
};

void test() {
    AbstractDrink* a1 = new coffee;
    a1->makeDrink();
    delete a1;
    a1 = new tea;
    a1->makeDrink();
    delete a1;

    coffee c1;
    AbstractDrink& a2 = c1;
    a2.makeDrink();
    AbstractDrink* a3 = &c1;
    a3->makeDrink();
    AbstractDrink& a4 = *new coffee;
    a4.makeDrink();

}
int main() {
    test();
    return 0;
}