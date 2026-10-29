#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
// 只读，不修改成员对象状态的函数加const
class people
{
  public:
    people()
    {
        m_capacity = 2;
        m_size = 0;
        m_data = new int[m_capacity];
    }
    void add(int value)
    {
        if (m_size == m_capacity)
        {
            resize(m_capacity * 2);
        }
        m_data[m_size] = value;
        m_size++;
    }
    int getsize() const
    {
        return m_size;
    }
    int getcapacity() const
    {
        return m_capacity;
    }
    void showdata() const
    {
        for (int i = 0; i < m_size; ++i)
        {
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }
    people(const people &p)
    {
        m_size = p.m_size;
        m_capacity = p.m_capacity;
        m_data = new int[p.m_capacity];
        for (int i = 0; i < m_size; i++)
        {
            m_data[i] = p.m_data[i];
        }
    }
    people &operator=(const people &p)
    {
        // if(*this == p){}不行，首先这段语句判断的是指针指向的内容是否相同，而非判断指针是否相同。另外判断指针指向的内容，即p1和p2是否相同还需要重载==
        if (this == &p)
        {
            return *this;
        }
        int *temp = new int[p.m_capacity];
        // 把new放在delete前，是为了避免内存不足，new失败，导致二次释放。另外选择临时变量temp是为了避免先覆盖m_data空间地址再delete，导致旧地址永久泄露
        delete[] m_data;
        m_capacity = p.m_capacity;
        m_size = p.m_size;
        m_data = temp;
        for (int i = 0; i < p.m_size; i++)
        {
            m_data[i] = p.m_data[i];
        }
        return *this;
    }
    ~people()
    {
        delete[] m_data;
    }

  private:
    void resize(int new_capacity)
    {
        int *temp = new int[new_capacity];
        for (int i = 0; i < m_size; i++)
        {
            temp[i] = m_data[i];
        }
        delete[] m_data;
        m_data = temp;
        m_capacity = new_capacity;
    }
    int m_capacity;
    int m_size;
    int *m_data;
};

int main()
{
    people p1;
    p1.add(10);
    std::cout << p1.getcapacity() << " ";
    p1.add(20);
    std::cout << p1.getcapacity() << " ";
    p1.add(40);
    std::cout << p1.getcapacity() << " ";
    p1.add(30);
    std::cout << p1.getcapacity() << " ";
    p1.add(50);
    std::cout << p1.getcapacity() << " ";
    p1.showdata();
    return 0;
}