#include<iostream>  
#include<sstream>        //istringstream 必须包含这个头文件
#include<string>  
using namespace std;  
int main()  
{  
    string str="i am a boy i ddd";  
    istringstream is(str);  
    cout<<is.beg<<endl;
    cout<<is.end<<endl;
    string s;  
    while(is>>s)  
    {  
        cout<<s<<endl;  
    }  
      
}
