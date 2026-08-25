#include <iostream>
using namespace std;
#include <string>
#include "class_point.h"
#include "class_circle.h"


void relation(circle& c1, point& p1) {
    int num1, num2;
    num1 = (c1.getcenter().getX() - p1.getX()) * (c1.getcenter().getX() - p1.getX()) + (c1.getcenter().getY() - p1.getY()) * (c1.getcenter().getY() - p1.getY());
    num2 = c1.getr() * c1.getr();
    if (num1 == num2) {
        cout << "1" << endl;
    }
    else if (num1 < num2) {
        cout << "2" << endl;
    }
    else if (num1 > num2) {
        cout << "3" << endl;
    }
}

int main() {
    circle c1;
    point center;
    c1.setr(10);
    center.setX(10);
    center.setY(0);
    c1.setcenter(center);//先设置圆心数据再传圆心给c1.setcenter(center)


    point p1;
    p1.setX(10);
    p1.setY(10);
    relation(c1, p1);

    point p2;
    p2.setX(5);
    p2.setY(5);
    relation(c1, p2);

    point p3;
    p3.setX(30);
    p3.setY(30);
    relation(c1, p3);


}