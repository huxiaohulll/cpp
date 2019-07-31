#include<iostream>
/*
3种：
作用域限定符
using 编译指令
using 声明机制
 */
using namespace std;//standard  using 编译指令


namespace wd
{
    int number= 10;
    void display()
    {
        cout<<"display()"<<endl;
    }
}

int main(void)
{
    cout<<wd::number<<endl;
    wd::display();//作用域限定符

    return 0;
}