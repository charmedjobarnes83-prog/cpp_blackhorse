#include "class_point.h"

void point::setX(int X) {//注:不是point::setr(),设置的类名是point
    m_x = X;
}
int point::getX() {
    return m_x;
}
void point::setY(int Y) {
    m_y = Y;
}
int point::getY() {
    return m_y;
}
