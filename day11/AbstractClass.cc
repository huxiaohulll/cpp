#include <iostream>
using std::cout;
using std::endl;


//抽象类：定义了protected的构造函数
class  Base
{
public:
    virtual void display() const
    {
        cout<<"_base ="<<_base<<endl;
    }
protected:
    Base(long base)
    :_base(base)
    {
        cout<<"base(long)"<<endl;

    }
private:
    long _base;
};

class Derived
:public Base
{
public: 
    Derived(long base,long derived)
    :Base(base)
    ,_derived(derived)
    {
        cout<<"Derived(long,long)"<<endl;
    }
    virtual void display() const
    {
        cout<<"_derived  ="<<_derived<<endl;
    }


private:
    long _derived;
};


int main(void)
{
    Derived derived(1,2);
    Base * pbase=& derived;
    pbase->display();
    //Base base(3); 抽象类不能创建对象
    

    return 0;
}