#include <iostream>
#include <functional>

using std::cout;
using std::endl;


class Example
{
public:
	Example()=default;

	void display()
	{
		cout << "Example::display()" << endl;
	}

	int add(int x, int y)
	{
		return x + y;
	}

	int _data = 10;
};
 

void display()
{
    cout<<"display()"<<endl;
}

void print(int a)
{
    cout<<"print()"<<a<<endl;
}



typedef void(*Function)();
typedef void(*Function1)(int);
void test1()
{
    Function f= display;
    f();
    
    Function1 f1=print;
    f1(1);

}

void test2()
{
    std::function<void()> f=display;
    f();

    Example e;
    f=std::bind(&Example::display,e);
    f();

   
}

void test3()
{
    using namespace std::placeholders;
   Example e;
   auto f4=std::bind(&Example::add,&e,_1,_2);
   cout<<f4(11,2)<<endl;

   auto f5=std::bind(&Example::add,&e,_1,10);
   cout<<f5(11)<<endl;

   auto f6=std::bind(&Example::_data,&e);
   cout<<f6()<<endl;

   auto f7=std::bind(&Example::add,e,_1,_2);
   cout<<f7(11,12)<<endl;


}




void func(int x1, int x2, int x3, int & x4)
{
	cout << "(" << x1 
		 << ", " << x2 
		 << ", " << x3 
		 << ", " << x4 
		 << ")" << endl;
}



void test4()
{
    using namespace std::placeholders;
     //std::ref 引用的包装器 ref可以传递引用
    int a=10;
    auto f=std::bind(func,_3,_4,a,std::ref(a));
    a=20;  
    f(11,22,33,44);
}

int main(void)
{
    // test1();
    // test2();
    // test3();
    test4();
}