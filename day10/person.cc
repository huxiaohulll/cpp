#include<string.h>
#include <iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;

/*
3. 构建一个类person，包含字符串成员name（姓名），整型数据成员age（年龄），成员函数
   display（）用来输出name和age。构造函数包含两个参数，用来对name和age初始化。
   
   构建一个类employee由person派生，包含department（部门），实型数据成员salary（工资）,
   成员函数display（）用来输出职工姓名、年龄、部门、工资，其他成员根据需要自己设定。
   
   主函数中定义3个employee类对象，内容自己设定，将其姓名、年龄、部门、工资输出，
   并计算他们的平均工资。


 */


class Person
{
    public:
    Person(string n,int a)
    :name(n)
    ,age(a)
    {
        cout<<"person(string,int)"<<endl;
    }

    void display()
    {
        cout<<name<<endl
            <<age<<endl;
    }
    protected: string name;
             int age;

};
/*

   
   构建一个类employee由person派生，包含department（部门），实型数据成员salary（工资）,
   成员函数display（）用来输出职工姓名、年龄、部门、工资，其他成员根据需要自己设定。
 */

class Employee:public Person
{
    public :
    Employee(string n,int a,int d,int s)
    :Person(n,a)
    ,department(d)
    ,salary(s)
    {
        cout<<"emplyoee(string,int,int,int)"<<endl;
    }
    void display()
    {
        cout<<name<<endl
            <<age<<endl
            <<salary<<endl
            <<department<<endl;
         
    }
    int getSalary()
    {
        return salary;
    }
    private: int salary;
             int department;

};

/*
 主函数中定义3个employee类对象，内容自己设定，将其姓名、年龄、部门、工资输出，
   并计算他们的平均工资。
 */

int main()
{
    Person p("hu",23);
    p.display();
    Employee e("patato",23,1,10000);
    e.display();
     Employee e1("tomata",23,2,20000);
    e1.display();
     Employee e2("jiangjiang",23,3,30000);
    e2.display();
    cout<<(e.getSalary()+e1.getSalary()+e2.getSalary())/3<<endl;


    return 0;
}