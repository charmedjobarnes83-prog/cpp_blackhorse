//员工文件
#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <worker.h>

class Employee :public Worker {
public:
    Employee(int id, string name, int careerid);
    void showinfo();
    string getcareer();
};