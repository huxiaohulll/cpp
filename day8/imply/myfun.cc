/*
1. 最内层  实现功能.cc
2. 中间层  最外层的内部类
3. 最外层  来测试中间给功能

 */

#include "myfun.h"
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

class look::impl//中间类
{
    class fun
    {
        public:
            fun(int x=0,int y=0)
            :x(x)
            ,y(y)
            {
                cout<<"fun(int ,int )"<<endl;

            }
            ~fun()
            {
                cout<<"~fun()"<<endl;
            }
            void print() const{
                cout<<"第一个数字是"<<x<<endl;
                cout<<"第二个数字是"<<y<<endl;
                
            }
            
        private:
            int x;
            int y;
    };
public:
    impl(int x1, int y1,int x2,int y2)
    : f1(x1,y1)
    ,f2(x2,y2)
    {
        cout<<"impl(int ,int ,int, int)"<<endl;

    }
    ~impl()
    {
        cout<<"~impl()"<<endl;
    }
    void printnumber() const;
private:
     fun f1;
     fun f2;


};

look::look(int x1, int y1,int x2,int y2)
:_pimpl(new impl(x1, y1, x2, y2))
{
      cout<<"look(,,,,,)"<<endl;
}


look::~look()
{
      cout<<"~look()"<<endl;
}

void look::print() const{

    _pimpl->printnumber();

}


void look::impl::printnumber() const
{
    f1.print();
    f2.print();
      
}