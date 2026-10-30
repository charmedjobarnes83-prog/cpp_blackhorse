#include <iostream>

struct ControlBlock
{
    int ref_count;
    ControlBlock() : ref_count(1)
    {
    }
};

template <typename T> class SimpleSharePtr
{
  private:
    T *ptr;
    ControlBlock *control;
    void release()
    {
        if (control)
        {
            --control->ref_count;
            std::cout << "ref_count:" << control->ref_count << std::endl;
            if (control->ref_count == 0)
            {
                delete ptr;
                delete control;
            }
        }
        ptr = nullptr;
        control = nullptr;
    }

  public:
    SimpleSharePtr() : ptr(nullptr), control(nullptr)
    {
        std::cout << "default construct" << std::endl;
    }
    explicit SimpleSharePtr(T *p) : ptr(p)
    {
        if (p)
        {
            control = new ControlBlock();
            std::cout << "constduct" << std::endl;
        }
        else
        {
            control = nullptr;
        }
    }
    SimpleSharePtr(const SimpleSharePtr &s1) : ptr(s1.ptr), control(s1.control)
    {
        if (control)
        {
            ++control->ref_count;
            std::cout << "copy construct count" << control->ref_count << std::endl;
        }
    }
    SimpleSharePtr &operator=(const SimpleSharePtr &s1)
    {
        if (this != &s1)
        {
            release();
            ptr = s1.ptr;
            control = s1.control;
            if (control)
            {
                ++control->ref_count;
                std::cout << "=construct" << control->ref_count << std::endl;
            }
        }
        return *this;
    }
    SimpleSharePtr(SimpleSharePtr &&s1) noexcept : ptr(s1.ptr), control(s1.control)
    {
        s1.ptr = nullptr;
        s1.control = nullptr;
        std::cout << "move construct" << std::endl;
    }
    SimpleSharePtr &operator=(SimpleSharePtr &&s1) noexcept
    {
        if (this != &s1)
        {
            release();
            ptr = s1.ptr;
            control = s1.control;
            s1.ptr = nullptr;
            s1.control = nullptr;
            std::cout << "= move construct" << std::endl;
        }
        return *this;
    }
    ~SimpleSharePtr()
    {
        release();
    }
    T &operator*() const
    {
        return *ptr;
    }
    T *operator->() const
    {
        return ptr;
    }
    int use_count() const
    {
        return control ? control->ref_count : 0;
    }
    T *get() const
    {
        return ptr;
    }
    void reset(T *p = nullptr)
    {
        release();
        ptr = p;
        if (p)
        {
            control = new ControlBlock();
            std::cout << "reset count" << control->ref_count << std::endl;
        }
        else
        {
            control = nullptr;
        }
    }
};

class student
{
  public:
    student(int val) : value(val)
    {
        std::cout << "student construct" << std::endl;
    }
    ~student()
    {
        std::cout << "student destruct" << std::endl;
    }
    void show() const
    {
        std::cout << "value:" << value << std::endl;
    }

  private:
    int value;
};

int main()
{
    SimpleSharePtr<student> s1;
    std::cout << "s1 count" << s1.use_count() << std::endl;
    SimpleSharePtr<student> s2(new student(100));
    std::cout << "s2 count" << s2.use_count() << std::endl;
    s2->show();
    SimpleSharePtr<student> s3 = s2;
    std::cout << "s2 count" << s2.use_count() << std::endl;
    std::cout << "s3 count" << s3.use_count() << std::endl;
    s3->show();
    /*SimpleSharePtr<student> s4(s2);
    std::cout << "s2 count" << s2.use_count() << std::endl;
    std::cout << "s3 count" << s3.use_count() << std::endl;
    std::cout << "s4 count" << s4.use_count() << std::endl;
    s4->show();*/
    s3 = s1;
    SimpleSharePtr<student> s4 = s1;
    std::cout << "s1 count" << s1.use_count() << std::endl;
    std::cout << "s2 count" << s2.use_count() << std::endl;
    std::cout << "s3 count" << s3.use_count() << std::endl;
    std::cout << "s4 count" << s4.use_count() << std::endl;
    //s4.reset(s2);
    s2.reset();
    s4.reset(new student(50));
    std::cout << "s1 count" << s1.use_count() << std::endl;
    std::cout << "s2 count" << s2.use_count() << std::endl;
    std::cout << "s3 count" << s3.use_count() << std::endl;
    std::cout << "s4 count" << s4.use_count() << std::endl;
    s4->show();
    return 0;
}