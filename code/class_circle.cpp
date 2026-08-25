#include "class_circle.h"
#include "class_point.h"

void circle::setr(int r) {//注:不是class_circle::setr(),设置的类名是circle
    m_r = r;
}
int circle::getr() {
    return m_r;
}
void circle::setcenter(point center) {
    m_center = center;
}
point circle::getcenter() {
    return m_center;
}
