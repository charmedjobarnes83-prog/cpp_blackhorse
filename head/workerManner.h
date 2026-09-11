#pragma once//防止头文件重复包含
#include <iostream>//包含输入输出流的头文件
using namespace std;//使用标准命名空间
#include <worker.h>
#include <employee.h>
#include <boss.h>
#include <manager.h>


class workerManner {
public:
    workerManner();
    void showmenu();
    void exitSystem();

    //记录职工人数
    int m_peoplenum;
    //职工数组指针
    Worker** m_array;
    //添加职工
    void add();



    ~workerManner();
};