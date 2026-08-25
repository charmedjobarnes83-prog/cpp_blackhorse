#pragma once
#include <iostream>
using namespace std;
#include "class_point.h"

class circle {
private:
    int m_r;
    point m_center;

public:
    void setr(int r);
    int getr();
    void setcenter(point center);
    point getcenter();

};