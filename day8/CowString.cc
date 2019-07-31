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
            cout<<"Cowstring(const char *)"<<endl;
             initcount();
             strcpy(_pstr,str);
             

        }
        CowString(const CowString& ctr)
        :_pstr(ctr._pstr)
        {
             //引用数+1;
             addcount();
             cout<<"Cowstring(const &str)"<<endl;

        }
        ~CowString()
        {
            cout<<"~cowstring()"<<endl;
            release();
          
        }

        CowString  & operator=(const CowString & cstr)//要把pstr转换为新的bowstring对象的pstr的地址
        {
            cout<<" cowstring operator="<<endl;
            if(this!=&cstr)//如果不是本对象
            {
                release();
                _pstr=cstr._pstr;//换地址
                addcount(); //计数+1

            }

            return * this;


        }
     

        char  & operator[](int index)//要把pstr转换为新的bowstring对象的pstr的地址，修改版本的
        {
            cout<<" cowstring operator[]"<<endl;
            if(index>0&&index<strlen(_pstr))//如果在此范围内，要换地址
            {
                //如果引用计数现在只为1呢
                if(recount()>1)
                {
                    subcount();
                    char * tmp=new char[5+strlen(_pstr)]()+4;//新建一个空间
                    strcpy(tmp,_pstr);
                    _pstr=tmp;
                    initcount();

                }
                return _pstr[index];  


            }
            else
            {
                static char nullchar='\0';
                return nullchar;
            }
            

            

        }

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



};


std::ostream & operator<<(std::ostream & os, const CowString & cstr)
{


    os<<cstr._pstr;
    return os;


}


int main()
{

    CowString s1="huwanting";
    CowString s2("huwanting");
    CowString s3=s1;//没用重载等于号
    s3=s1;
    

    cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1's address is %p\n", s1.c_str());
	printf("s2's address is %p\n", s2.c_str());
	printf("s3's address is %p\n", s3.c_str());
	cout << "s1's refcount = " << s1.recount() << endl;
	cout << "s2's refcount = " << s2.recount() << endl;
	cout << "s3's refcount = " << s3.recount() << endl;

    s3[2]='o';


    cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1's address is %p\n", s1.c_str());
	printf("s2's address is %p\n", s2.c_str());
	printf("s3's address is %p\n", s3.c_str());
	cout << "s1's refcount = " << s1.recount() << endl;
	cout << "s2's refcount = " << s2.recount() << endl;
	cout << "s3's refcount = " << s3.recount() << endl;
    

}