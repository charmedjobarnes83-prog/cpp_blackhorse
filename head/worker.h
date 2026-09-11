#pragma once
#include <iostream>
using namespace std;
#include <string>
//抽象类，不需要实现，所以连worker.cpp都不需要创建
class Worker {
public:
    //获取个人信息
    virtual void showinfo() = 0;
    //获取岗位名
    virtual string getcareer() = 0;

    int m_id;
    string m_name;
    int m_careerid;
};