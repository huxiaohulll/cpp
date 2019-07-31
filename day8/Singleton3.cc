#include<iostream>
#include<pthread.h>
using std::cout;
using std::endl;

//pthread_once+atexit,保证多线程安全，所以可以用饿汉

class singleton
{
     
public:
    static singleton * getInstance()
    {
       
         
        pthread_once(&once,init);//只会执行一次init
         
        return _pInstance;
    }
    static void init()
    {
        _pInstance=new singleton();
        ::atexit(destory);//注册
    }
    static void destory()
    {
         if(_pInstance)
         {
             delete _pInstance;
         }
    }
   
private:
    singleton(){   cout<<"singleton()"<<endl; }
    ~singleton(){   cout<<"~singleton()"<<endl;}
private:
    static singleton * _pInstance;
    //非静态的话就是单例对象的一部分，就不能删除单例
    static pthread_once_t once;

};
//累的静态成员：必须在类的外部定义和初始化每个静态成员
singleton * singleton::_pInstance= nullptr;
pthread_once_t singleton::once=PTHREAD_ONCE_INIT;


int main(void)
{
    singleton * p1 = singleton::getInstance();
    singleton * p2 = singleton::getInstance();
    singleton * p3 = singleton::getInstance();
    cout<<p1<<endl;
    cout<<p1<<endl;
    cout<<p1<<endl;
    return 0;

}