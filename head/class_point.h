#pragma once
#include <iostream>
using namespace std;


class point {
private:
    int m_x;
    int m_y;

public:
    void setX(int X);
    int getX();
    void setY(int Y);
    int getY();

};