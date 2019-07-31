#pragma once  //只编译一次

#include <stdio.h>
#include<string>
#include <iostream>
using std::cout;
using std::endl;


class look
{
      class impl;//创建一个中间类
public:
     look(int ,int ,int,int);
     ~look();
     void print() const;
private: 
    impl * _pimpl;

};