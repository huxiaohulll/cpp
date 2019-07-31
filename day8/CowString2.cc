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

/*
1.重载[] 运算符 返回设置一个代理类 
2. 在代理类中：
           a. 重载 =  进行写操作
           b. 重载 << 进行读操作  /  类型转换  （两种方法）




 */

class CowString
{
    class CharProxy
	{
	public:
		CharProxy(CowString & s, int i)//形参名和成员函数名字 不能一样吗
		: self(s)
		, index(i)
		{}

		//CharProxy & operator=(const char & ch);
		//CharProxy & operator=(const CharProxy & rhs);
		//执行写操作
		char & operator=(const char & ch);

		//执行读操作
		operator char() {	
			//cout << "operator char()" << endl;	
			return self._pstr[index]; 
		}
	private:
		CowString & self;
		int index;
	};

  
    // class CharProxy
    // {

    //     public : 
    //             CharProxy( CowString & ctr,int index)
    //             :self(ctr)
    //             ,index(index)
    //             {
    //                 cout<<"charproxy()"<<endl;
    //             }

    //             char & operator= (const char & ch);//写操作
                
    //             //读操作
    //             //1.重载<<
    //             friend std::ostream & operator<<(std::ostream,const CharProxy &  rhs);
    //             //2.类型转换
                 
    //     private :
    //             CowString  & self;   //疑问
    //             int index;
    // };
    public:
        //构造函数
        CowString()
        :_pstr(new char[5]()+4)
        {
            //引用数初始化为1
            initcount();
            cout<<"Cowstring()"<<endl;

        }
         //构造函数
        CowString(const char * str)
        :_pstr(new char[5+strlen(str)]()+4)
        {
            cout<<"Cowstring(const char *)"<<endl;
             initcount();
             strcpy(_pstr,str);
             

        }
         //构造函数
        CowString(const CowString& ctr)
        :_pstr(ctr._pstr)
        {
             //引用数+1;
             addcount();
             cout<<"Cowstring(const &str)"<<endl;

        }
        //析构函数
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
     
        //区分读写，要重载[],返回一个代理类
        CharProxy  operator[](int index);//要把pstr转换为新的bowstring对象的pstr的地址，修改版本的
        
        friend  std::ostream & operator<<(std::ostream & os, const CowString & cstr);
       // friend std::ostream & operator<<(std::ostream & os, const CharProxy & rhs);
        const char* c_str() const
        {
            return _pstr;

        }
         int recount()
        {
            return *(int*)(_pstr-4);
        }

        int size()
        {
            return strlen(_pstr);
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
CowString::CharProxy CowString::operator[](int index) 
{
     return CharProxy(*this,index);  //不能返回charproxy &

}

std::ostream & operator<<(std::ostream & os, const CowString & cstr)
{


    os<<cstr._pstr;
    return os;


}

//写操作
char & CowString::CharProxy::operator=(const char & ch)
{

    if(index>=0&&index<strlen(self._pstr))//在此范围内
    {
        if(self.recount()>1)
        {
            self.subcount();//计数减一
            char * ptm=new char [self.size()+5]()+4;
            strcpy(ptm,self._pstr);
            self._pstr=ptm;
            self.initcount();

        }
        self._pstr[index]=ch;
        return self._pstr[index];

    }
    else
    {
        static char nullchar='\0';
        return nullchar;
    }
    

}

//读操作




int main()
{
CowString s1 = "hello,world";

	//CowString s2 = "hello,world";
	CowString s2 = s1;

	CowString s3 = "shenzhen";
	cout << "s3 = " << s3 << endl;
	s3 = s1;
 
	cout << "执行赋值操作之后:" << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1's address is %p\n", s1.c_str());
	printf("s2's address is %p\n", s2.c_str());
	printf("s3's address is %p\n", s3.c_str());
	cout << "s1's refcount = " << s1.recount() << endl;
	cout << "s2's refcount = " << s2.recount() << endl;
	cout << "s3's refcount = " << s3.recount() << endl;

	cout << "\n 修改共享字符串的内容之后:" << endl;
	s3[0] = 'X';
				// CharProxy = char;
				// CharProxy ch;
				// ch.operaotr=(char);
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1's address is %p\n", s1.c_str());
	printf("s2's address is %p\n", s2.c_str());
	printf("s3's address is %p\n", s3.c_str());
	cout << "s1's refcount = " << s1.recount() << endl;
	cout << "s2's refcount = " << s2.recount() << endl;
	cout << "s3's refcount = " << s3.recount() << endl;

	cout << "\n 执行读操作之后:" << endl;
	cout << "s1[0] = " << s1[0] << endl;//CharProxy ==> char
	// cout << CharProxy
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1's address is %p\n", s1.c_str());
	printf("s2's address is %p\n", s2.c_str());
	printf("s3's address is %p\n", s3.c_str());
	cout << "s1's refcount = " << s1.recount() << endl;
	cout << "s2's refcount = " << s2.recount() << endl;
	cout << "s3's refcount = " << s3.recount() << endl;

	return 0;
    

}