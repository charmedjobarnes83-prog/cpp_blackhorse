#pragma once 
#include <iostream>
using namespace std;

template <class T>
class MyArray {
public:
    MyArray(int capacity) {
        //cout << "有参构造" << endl;
        this->m_capacity = capacity;
        this->m_size = 0;
        this->pAddress = new T[this->m_capacity];
    }
    //拷贝构造函数
    MyArray(const MyArray& arr) {
        //cout << "拷贝构造" << endl;
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;

        //深拷贝
        this->pAddress = new T[arr.m_capacity];
        //将arr中的数据拷贝
        for (int i = 0;i < this->m_capacity;i++) {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    //operator= 防止浅拷贝
    MyArray& operator=(const MyArray& arr) {
        //cout << "=重载" << endl;
        if (this->pAddress != nullptr) {
            delete[] this->pAddress;
            this->pAddress = nullptr;//置空，防止变为野指针
            this->m_capacity = 0;
            this->m_size = 0;
        }
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->pAddress = new T[arr.m_capacity];
        for (int i = 0;i < this->m_capacity;i++) {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }
    //尾插法
    void push_back(const T& val) {
        if (this->m_capacity == this->m_size) {
            return;
        }
        this->pAddress[this->m_size] = val;//在数组尾部插入数据
        this->m_size++;//更新数组大小
    }
    //尾删法
    void pop_back() {
        //让用户无法访问到最后一个元素
        if (this->m_size == 0) {
            return;
        }
        this->m_size--;
    }
    //通过下标访问数组中的元素，因为此数组是自定义类型的，要重载[]
    T& operator[](int index) {//引用的目的是为了连续调用，返回数据本身
        return this->pAddress[index];
    }
    int getcapacity() {
        return this->m_capacity;
    }
    int getsize() {
        return this->m_size;
    }
    ~MyArray() {
        //cout << "析构函数" << endl;
        if (this->pAddress != nullptr) {
            delete[] this->pAddress;
            this->pAddress = nullptr;//置空，防止变为野指针
        }
    }
private:
    T* pAddress;   //指针指向堆区开辟的真实数组
    int m_capacity; //数组容量
    int m_size;     //数组大小
};