#include<iostream>
using std::cout;
using std::endl;


class singleton
{
     class Autorelease
    {
        public:
            Autorelease(){cout<< " Autorelease()"<<endl;}
            ~Autorelease()
            {
                cout<< "~Autorelease()"<<endl;
                if(_pInstance)
                {
                    delete _pInstance;
                }
                
            }
    };
  
public:
    static singleton * getInstance()
    {
        if(nullptr==_pInstance)//如果当前没有实例
        {
            _pInstance=new singleton();//创建
        }
        return _pInstance;
    }
     
   
private:
    singleton(){   cout<<"singleton()"<<endl; }
    ~singleton(){   cout<<"~singleton()"<<endl;}
private:
    static singleton * _pInstance;
    //非静态的话就是单例对象的一部分，就不能删除单例
    static Autorelease _auto;
};

singleton * singleton::_pInstance= singleton::getInstance();

singleton::Autorelease singleton::_auto;

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