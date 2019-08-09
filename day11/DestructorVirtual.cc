#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base(const char *base)
    :_pbase(new char[strlen(base)+1]())
    {
        cout<<"base(long)"<<endl;
        strcpy(_pbase,base);

    }
    virtual void display() const
    {
        cout<<"_pbase"<<_pbase<<endl;
    }



    virtual
    ~Base()
    {
        if(_pbase)
            delete []_pbase;
        cout<<"~base()"<<endl;
    }
private:
    char * _pbase;
};


class Derived
:public Base
{
public :
    Derived(const char* base,const char * derived)
    :Base(base)
    ,_pderived(new char[strlen(derived)+1]())
    {
        strcpy(_pderived,derived);

    }
    void display() const
	{
		cout << "_pderived = " << _pderived << endl;
	}
    ~Derived()
    {
        if(_pderived)
            delete[] _pderived;
        cout<<"~ Derived()"<<endl;
    }
private:
    char * _pderived;
};


int main(void)
{
    Base * pbase= new Derived("hu","wanting");
    pbase->display();

    delete pbase;

    return 0;
}