#include <string.h>

#include <string>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector; 
using std::string;



class String {
public:
	String() = default;

	String(const char * str)
    :_pstr(new char[strlen(str)+ 1]())
    {
          strcpy(_pstr,str);
          cout<<"String(const char *)"<<endl;
    }


	String(const String& str)
    :_pstr(new char[str.size()+ 1]())
    {
          strcpy(_pstr,str.c_str());
          cout<<"String(const char &)"<<endl;

    }

	~String()
    {
        if(_pstr)
        {
            delete [] _pstr;
        }
        cout<<"~String()"<<endl;


    }
	String &operator=(const String &);
	String &operator=(const char *);

	String &operator+=(const String &);
	String &operator+=(const char *);

	char &operator[](std::size_t index);
	const char &operator[](std::size_t index) const;

	std::size_t size() const;
	const char* c_str() const;

	friend bool operator==(const String &, const String &);
	friend bool operator!=(const String &, const String &);

	friend bool operator<(const String &, const String &);
	friend bool operator>(const String &, const String &);
	friend bool operator<=(const String &, const String &);
	friend bool operator>=(const String &, const String &);

	friend std::ostream &operator<<(std::ostream &os, const String &s);
	friend std::istream &operator>>(std::istream &is, String &s);
    char * getstr()
    {
        return _pstr;
    }

private:
	char * _pstr;
};

String operator+(const String & str1, const String &str2)
{
    char *ch3;
    ch3=new char[str1.size()+str2.size()+1]();
    strcpy(ch3,str1.c_str());
    strcat(ch3,str2.c_str());
    return  String(ch3);

     
}
String operator+(const String &str1, const char *str2)
{
    char *ch3;
    ch3=new char[str1.size()+strlen(str2)+1]();
    strcpy(ch3,str1.c_str());
    strcat(ch3,str2);
    return  String(ch3);

}
String operator+(const char * str1, const String &str2)
{
       char *ch3;
    ch3=new char[str2.size()+strlen(str1)+1]();
    strcpy(ch3,str1);
    strcat(ch3,str2.c_str());
    return  String(ch3);

    
}

std::size_t String::size() const
{
    if(_pstr)
        return strlen(_pstr);
    else
        return 0;
    
}

const char* String::c_str() const
{
    return _pstr;

}

String & String::operator=(const String & str1)
{
  
   if(this!=&str1)
   {
       delete[]_pstr;//回收左操作数空间
       _pstr=new char[strlen(str1._pstr)+1]();//深拷贝
       strcpy(_pstr,str1._pstr);
   }
   return *this;

}

String & String::operator=(const char * str1)
{
    String tmp(str1);
    *this = tmp;
    return *this;

}
bool operator==(const String & lhs, const String &rhs)
{
    return !strcmp(rhs.c_str(),lhs.c_str());
}

bool operator!=(const String & lhs, const String &rhs)
{
    return !(lhs==rhs);
}

 String & String::operator+=(const String & str1)
 {
     char *temp=_pstr;
     _pstr=new char[str1.size()+strlen(_pstr)+1];
     if(!temp)
     strcpy(_pstr,temp);
     strcat(_pstr,str1.c_str());
     delete []temp;
     return * this;

 }


String & String::operator+=(const char * str1)
{

    String tmp(str1);
    *this +=tmp;
    return * this;
  
  

}

bool operator<(const String &str1, const String &str2)
{
    int retval=strcmp(str1.c_str(),str2.c_str());
    if(retval<0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

bool operator>(const String &str1, const String &str2)
{
     int retval=strcmp(str1.c_str(),str2.c_str());
    if(retval>0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}


bool operator<=(const String &lhs, const String &rhs)
{
   if(lhs < rhs || lhs == rhs)
    {
        return true;
    }else {
        return false;
    }
}

bool operator>=(const String &lhs, const String &rhs)
{
    if(lhs > rhs || lhs == rhs)
    {
        return true;
    }else {
        return false;
    }
     
    
}

std::ostream &operator<<(std::ostream &os, const String &s)
{
    os<<s.c_str();
    return os;
}

std::istream &operator>>(std::istream &is, String &s)
{
    
    vector<char> buff;
	buff.reserve(65535);

	char ch ;
	while((ch = is.get()) != '\n') {
		buff.push_back(ch);
	}

	s = &buff[0];
	
	return is;
}


char & String::operator[](std::size_t index)
{
      
        if(index < strlen(_pstr) && index >=0) {
      return _pstr[index];
    } else {
      static char nullchar = '\0';
      return nullchar;
    }
   
     
        
        
            
        
}
const char & String::operator[](std::size_t index) const
{
     
              return _pstr[index];
     
    
            

}




int main()
{

//    
//     bool flag=(s2==s1);
//     cout<<flag<<endl;
//      s2+=s1;
//    cout<<s2.c_str()<<endl;
//      s2+=test;
//    cout<<s2.c_str()<<endl;
// const char * test1="aaaa";
// const char * test2="aaa";
//     cout<<(s2<s1)<<endl;
//     cout<<(strcmp(test2,test1))<<endl;
//      cout<<s2<<endl;
//      std::cin >> s2;

// 	cout << "s2 = " << s2 << endl;
    
//    cout << "s2[] = " << s2[1] << endl;
//    s2[1]='h';
//     cout << "s2[] = " << s2[1] << endl;
//     	cout << "s2 = " << s2 << endl;
    //    cout<<(s1+s2).c_str()<<endl;
    //    cout<<(s1+test).c_str()<<endl;
    //         cout<<(test+s2).c_str()<<endl;
    //  const char * p="hhh";
    //  char * pp=new char[10]();
    //  strcat(pp,p);
    //  cout<<pp<<endl;
    String s1("sdsfsf");
    cout<<s1[1]<<endl;
      cout<<s1[16]<<endl;
    

    return 0;
}