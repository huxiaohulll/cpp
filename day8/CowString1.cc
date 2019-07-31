#include <iostream>
#include<string.h>
using std::cout;
using std::endl;

/*
构造函数 1. 参数为空
        2. 字符串
        3. 对象
重载  =:  指向同一个堆空间
     <<:  输出string
     []:  修改后 得到新地址
     []:  查看后 不修改地址
    
引用数 : 初始化
        加1
        减1
        释放空间


 */

class CowString
{
     class charProxy;
    public:
        CowString()
        :_pstr(new char[5]()+4)
        {
            //引用数初始化为1
            initcount();
            cout<<"Cowstring()"<<endl;

        }
        CowString(const char * str)
        :_pstr(new char[5+strlen(str)]()+4)
        {
             initcount();
             strcpy(_pstr,str);
             cout<<"Cowstring(const char *)"<<endl;

        }
        CowString(CowString& ctr)
        :_pstr(ctr._pstr)
        {
             //引用数+1;
             addcount();
             cout<<"Cowstring(const char *)"<<endl;

        }
        ~CowString()
        {
            cout<<"~cowstring()"<<endl;
            release();
          
        }
        CowString& operator=(const CowString& cstr) //cowstring 的 =
        {
            

                //  cout<<"cowString& operator=(const String&)"<<endl;
                //  subcount();
                //  if(0==recount())
                //  {
                //       delete [](_pstr-4);
                //  }
                //  _pstr = cstr._pstr; 
                //  addcount();
                //  return *this; 
                 cout<<" cowstring operator="<<endl;
            if(this!=&cstr)//如果不是本对象
            {
                release();
                _pstr=cstr._pstr;//换地址
                addcount(); //计数+1

            }

            return * this;


        }
        charProxy operator[](int index); 
        

        friend  std::ostream & operator<<(std::ostream & os, const CowString & cstr);
        const char* c_str() const
        {
            return _pstr;

        }
         int recount()
        {
            return *(int*)(_pstr-4);
        }



    private:
        void initcount()
        {
             *(int*)(_pstr-4)=1;
        }
        void addcount()
        {
            (*(int*)(_pstr-4))++;

        }
        void subcount()
        {
            (*(int*)(_pstr-4))--;
          
        }
        void release()
        {

            subcount();
            if(recount()==0)//如果为0,销毁该空间
            {
                cout<<"delete data!"<<endl;
                printf("delete's address is %p\n", _pstr);
                delete [](_pstr-4);
            }

        }
     
    private:
        char * _pstr;
        class charProxy
                {
                        public:  //这些函数一定要是公有
                                charProxy(CowString& str,int index):_str(str),_index(index)
                                {
                                        cout<<"charProxy(String&,int)"<<endl;
                                }
                                char& operator=(char ch);         //嵌套类里面，也不能返回对象引用;因为嵌套类对象都是临时的
                                operator char()
                                { //类型转换函数，由Charproxy转向char
                                        cout<<"operator char()"<<endl;
                                        return _str._pstr[_index];
                                }
                        private:
                                CowString& _str;
                                int _index;
                };



};


std::ostream & operator<<(std::ostream & os, const CowString & cstr)
{


    os<<cstr._pstr;
    return os;


}



CowString::charProxy CowString::operator[](int index)
{
        cout<<"charProxy operator[](int)"<<endl;
        return charProxy(*this,index);     //返回临时嵌套类对象
}
char& CowString::charProxy::operator=(char ch)
{
        cout<<"char& operator=(char)"<<endl;
        if(_index>=0&&_index<strlen(_str._pstr))
        {
                if(1==_str.recount())  //当对象没有共享内存时
                {
                        _str._pstr[_index] = ch;  //修改
                        return _str._pstr[_index];
                }
                else
                {
                        _str.subcount();  //有共享内存
                        char* _strtmp = new char[strlen(_str._pstr)+2];
                        strcpy(_strtmp,_str._pstr);
                        _str = _strtmp;  //这里调用了构造函数和赋值构造函数,操作完之后调用析构函数
                        _str[_index] = ch;  //这里再次调动[]重载函数,进行修改
                        _str.initcount();
                        return _str._pstr[_index];
                }
        }
}


int main()
{

    // CowString s1("huwanting");
    // CowString s2("huwanting");
    // CowString s3=s1;

    // cout << "s1 = " << s1 << endl;
	// cout << "s2 = " << s2 << endl;
	// cout << "s3 = " << s3 << endl;
	// printf("s1's address is %p\n", s1.c_str());
	// printf("s2's address is %p\n", s2.c_str());
	// printf("s3's address is %p\n", s3.c_str());
	// cout << "s1's refcount = " << s1.recount() << endl;
	// cout << "s2's refcount = " << s2.recount() << endl;
	// cout << "s3's refcount = " << s3.recount() << endl;

    // s3[2]='o';


    // cout << "s1 = " << s1 << endl;
	// cout << "s2 = " << s2 << endl;
	// cout << "s3 = " << s3 << endl;
	// printf("s1's address is %p\n", s1.c_str());
	// printf("s2's address is %p\n", s2.c_str());
	// printf("s3's address is %p\n", s3.c_str());
	// cout << "s1's refcount = " << s1.recount() << endl;
	// cout << "s2's refcount = " << s2.recount() << endl;
	// cout << "s3's refcount = " << s3.recount() << endl;

        CowString s1("hello,world");
        CowString s2(s1);
        cout<<"读操作："<<s1[1]<<endl;
        cout<<s1.recount()<<endl;
        cout<<"--------------------------"<<endl;
        cout << "s1 = " << s1 << endl;
	    cout << "s2 = " << s2 << endl;
        printf("s1's address is %p\n", s1.c_str());
        printf("s2's address is %p\n", s2.c_str());
        cout<<"写操作："<<endl;
        s1[1] = 'm';
        cout<<"--------------------------"<<endl;
        cout<<s1[1]<<endl;
        cout<<s1.recount()<<endl;
        cout << "s1 = " << s1 << endl;
	     cout << "s2 = " << s2 << endl;
         printf("s1's address is %p\n", s1.c_str());
        printf("s2's address is %p\n", s2.c_str());
        return 0;
    


}