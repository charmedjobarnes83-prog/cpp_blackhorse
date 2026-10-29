#include <cstddef>
#include <iostream>
#include <new>
#include <stdexcept>
#include <vector>

class MemoryPool
{
  public:
    MemoryPool(size_t objectSize, size_t poolSize) : objSize(objectSize), pool(objectSize * poolSize)
    {
        for (size_t i = poolSize; i > 0; --i)
        {
            freeList.push_back(pool.data() + (i - 1) * objectSize);
        }
    }

    void *allocate()
    {
        if (freeList.empty())
        {
            throw std::bad_alloc();
        }
        void *ptr = freeList.back();
        freeList.pop_back();
        return ptr;
    }

    void deallocate(void *ptr)
    {
        freeList.push_back(static_cast<char *>(ptr));
    }

    size_t freeCount() const
    {
        return freeList.size();
    }

  private:
    size_t objSize;
    std::vector<char> pool;
    std::vector<char *> freeList;
};

int aliveCount = 0;

class MyClass
{
  public:
    MyClass(int val) : value(val)
    {
        heavy = new int(value * 10);
        ++aliveCount;
        std::cout << "MyClass constructor: " << value << std::endl;
    }
    ~MyClass()
    {
        delete heavy;
        --aliveCount;
        std::cout << "MyClass destructor: " << value << std::endl;
    }
    int value;
    int *heavy;
};

int main()
{
    MemoryPool pool(sizeof(MyClass), 3);
    std::cout << "free slots after init: " << pool.freeCount() << std::endl;

    void *mem1 = pool.allocate();
    MyClass *obj1 = new (mem1) MyClass(100); //(mem1)代表此次new的内存由mem1提供

    void *mem2 = pool.allocate();
    MyClass *obj2 = new (mem2) MyClass(200);

    std::cout << "free slots after 2 allocate: " << pool.freeCount() << std::endl;
    std::cout << "obj1->value = " << obj1->value << ", *obj1->heavy = " << *obj1->heavy << std::endl;
    std::cout << "obj2->value = " << obj2->value << ", *obj2->heavy = " << *obj2->heavy << std::endl;

    obj1->~MyClass();
    obj2->~MyClass();

    pool.deallocate(mem1);
    pool.deallocate(mem2);
    std::cout << "free slots after 2 deallocate: " << pool.freeCount() << std::endl;

    void *mem3 = pool.allocate();
    MyClass *obj3 = new (mem3) MyClass(300);
    std::cout << "obj3 reuse mem2's slot? " << (mem3 == mem2 ? "yes" : "no") << std::endl;

    obj3->~MyClass();
    pool.deallocate(mem3);

    std::cout << "aliveCount (0 means no leak) = " << aliveCount << std::endl;
    std::cout << "free slots at end: " << pool.freeCount() << std::endl;

    return 0;
}
