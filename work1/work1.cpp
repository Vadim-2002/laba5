#include <iostream>
#include <cstdlib>

class Base
{
    public:
    Base()
    {
        printf("\nBase()\n");
    }

    virtual ~Base()
    {
        printf("\nvirtual ~Base()\n");
    }

    void method_one()
    {
        method_two();
        printf("\nmethod_one from Base\n");
    }

    void method_two()
    {
        printf("\nmethod_two from Base\n");
    }

    void method_first()
    {
        methot_second();
        printf("\nmethod_first from Base\n");
    }

    virtual void methot_second()
    {
        printf("\nvirtual method_second from Base");
    }

    void method_not_virtual()
    {
        printf("\nmethod_not_virtual from Base\n");
    }

    virtual void method_virtual()
    {
        printf("\nmethod_virtual from Base\n");
    }
};

class One : public Base
{
    public:
    One()
    {
        printf("\nOne()\n");
    }

    ~One()
    {
        printf("\n~One()");
    }

    void method_two()
    {
        printf("\nmethot_two from One\n");
    }

    void method_second()
    {
        printf("\nmethod_second from One\n");
    }

    void method_not_virtual()
    {
        printf("\nmethod_not_virtual from One\n");
    }

    virtual void method_virtual()
    {
        printf("\nmethod_virtual from One\n");
    }
};

int main()
{
    {
    Base base;
    base.method_two();
    }

    printf("\n++++++++++++++++++++++++++++++++++++++++++\n");

    {
    One one;
    one.method_one();
    one.method_first();
    }

    printf("\n++++++++++++++++++++++++++++++++++++++++++\n");

    Base* base = new Base;
    base->method_not_virtual();
    base->method_virtual();

    printf("\n++++++++++++++++++++++++++++++++++++++++++\n");

    One* one = new One;
    one->method_not_virtual();
    one->method_virtual();

    delete base;
    delete one;

    system("pause");
    return 0;
}