#include <iostream>
#include <cstdlib>
#include <string>
#include <memory>

class Base
{
public:
    Base()
    {
        printf("\nBase()\n");
    }

    Base(Base* obj)
    {
        printf("\nBase(Base* obj)\n");
    }

    Base(Base& obj)
    {
        printf("\nBase(Base& obj)\n");
    }

    ~Base()
    {
        printf("\n~Base\n");
    }
};

class Desc : public Base
{
public:
    Desc()
    {
        printf("\nDesc()\n");
    }

    Desc(Desc* obj)
    {
        printf("\nDesc(Desc* obj)\n");
    }

    Desc(Desc& obj)
    {
        printf("\nDesc(Desc& obj)\n");
    }

    ~Desc()
    {
        printf("\n~Desc\n");
    }
};

void func1(Base  obj)
{
    printf("\nfunc1(Base obj)\n");
}

void func2(Base* obj)
{
    printf("\nfunc2(Base* obj)\n");
}

void func3(Base &obj)
{
    printf("\nfunc3(Base &obj)\n");
}

Base func1_base(Base obj) 
{
    printf("\nfunc1_base(Base obj)\n");
    return obj;
}

Base* func2_base(Base* obj) 
{
    printf("\nfunc2_base(Base* obj)\n");
    return obj;
}

Base& func3_base(Base &obj) 
{
    printf("\nfunc3_base(Base &obj)\n");
    return obj;
}

int main()
{
    Base* base = new Base();

    func1(*base);
    func2(base);
    func3(*base);

    func1_base(*base);
    func2_base(base);
    func3_base(*base);

    delete base;

    Desc* desc = new Desc();

	func1(*desc);
	func2(desc);
	func3(*desc);

	delete desc;

    printf("\n++++++++++++++++++++++++++++++++++++++++++\n");

    /*Умные указатели С++*/

    {
		std::unique_ptr<Desc> ptr1(new Desc());
	}

    {
        std::shared_ptr<Base> ptr2(new Base());
    }

    system("pause");
    return 0;
}