#include<iostream>

using std::cout;// using 声明机制
using std::endl;

namespace tls
{
    int show();//函数的声明
    namespace hwt{   //命名空间嵌套使用
        int display()
        {
             cout<<"hwt::display()"<<endl;

        }
    }
}

namespace wd
{
    int number= 10;
    void display()
    {
        cout<<"wd::display()"<<endl;
        tls::show();
    }
}
namespace tls
{
    int number= 10;
    void print()
    {
        cout<<"tls::print()"<<endl;
        wd::display();
    }
    int show()
    {
         cout<<"tls::show()"<<endl;
         return 0;

    }
}

int main(void)
{
    cout<<wd::number<<endl;
    tls::print();//作用域限定符
    tls::hwt::display();
    return 0;
}