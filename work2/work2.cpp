#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

class Base
{
    public:
    Base()
    {
        printf("\nBase()\n");
    }

    ~Base()
    {
        printf("\n~Base()\n");
    }

    virtual std::string classname()
    {
        return "Base";
    }

    virtual bool isA(std::string name)
    {
        if ("Base" == name)
            return true;
        else
            return false;
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
        printf("\n~One()\n");
    }

    std::string classname() override
    {
        return "One";
    }

    bool isA(std::string name) override
    {
        if ("One" == name)
            return true;
        else
            return false;
    }

    void test_one()
    {
        printf("\nWorks class one\n");
    }
};

class Two : public Base
{
    public:
    Two()
    {
        printf("\nTwo()\n");
    }

    ~Two()
    {
        printf("\n~Two()\n");
    }

    std::string classname() override
    {
        return "Two";
    }

    bool isA(std::string name) override
    {
        if ("Two" == name)
            return true;
        else
            return false;
    }

    void test_two()
    {
        printf("\nWorks class two\n");
    }
};

int main()
{
    /*Проверка на принадлежность классу с помощью метода classname*/

    Base* one1 = new One();
    Base* two1 = new Two();

    if (one1->classname() == "One")
        ((One*)one1)->test_one();

    if (two1->classname() == "Two")
        ((Two*)two1)->test_two();

    delete one1;
    delete two1;

    printf("\n++++++++++++++++++++++++++++++++++++++++++\n");

    /*Опасное приведение типов с помощью isA*/

    Base* one2 = new One();
    Base* two2 = new Two();

    if (one2->isA("One"))
        ((One*)one2)->test_one();

    if (two2->isA("Two"))
        ((Two*)two2)->test_two();

    delete one2;
    delete two2;

    printf("\n++++++++++++++++++++++++++++++++++++++++++\n");

    /*Опасное приведение типов*/

    Base* b;

    srand(time(NULL));
    if (rand()%2 == 0)
        b = new One();
    else
        b = new Two();

    ((One*)b)->test_one();

    delete b;

    printf("\n++++++++++++++++++++++++++++++++++++++++++\n");

    /*Безопасное приведение типов с помощью dynamic_cast*/

    Base* base;

    srand(time(NULL));
    if (rand()%2 == 0)
        base = new One();
    else
        base = new Two();

    if (dynamic_cast<One*>(base))
	    ((One*)base)->test_one();

    if (dynamic_cast<Two*>(base))
        ((Two*)base)->test_two();

    delete base;

    printf("\n++++++++++++++++++++++++++++++++++++++++++\n");

    system("pause");
    return 0;
}