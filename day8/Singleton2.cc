#include<iostream>
using std::cout;
using std::endl;

//静态成员函数+atexit

class singleton
{
     
public:
    static singleton * getInstance()
    {
        if(nullptr==_pInstance)//如果当前没有实例
        {
            //创建的时候注册
            _pInstance=new singleton();//创建
            atexit(destory);
        }
        return _pInstance;
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

};

singleton * singleton::_pInstance= singleton::getInstance();


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