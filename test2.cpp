#include <iostream>
#include <string>

class A
{
private:
    /* data */
public:
    A() {};
    void foo()
    {
        std::cout << "A::foo" << std::endl;
    }
};

class B : public A
{
private:
    /* data */
public:
    B() {};

    void foo()
    {
        std::cout << "B::foo" << std::endl;
    }
};

int main()
{
    A a;
    a.foo();
    B b;
    b.A::foo();
    return 0;
}
