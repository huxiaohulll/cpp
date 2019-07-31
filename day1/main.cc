/*
自定义头文件放在最前面，c头文件要放在c++头文件前面

“”和<>的区别：“”先在当前路径查找头文件，再去系统路径进行查找

 */
#include<stdio.h>
#include<iostream>

using namespace std;//命名空间，

int main(int argc,char **argv)
{
    printf("hello,world\n");
    cout<<"hello,huwanting"<<endl;
    return 0;
}
