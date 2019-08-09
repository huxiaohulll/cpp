#include <iostream>
#include<string.h>
using std::cout;
using std::endl;

#define pai 3.14
/*
1. 编写一个圆类Circle，该类拥有： 
		① 1个成员变量，存放圆的半径；
		② 两个构造方法
	 			Circle( )              // 将半径设为0           
	 			Circle(double  r )     //创建Circle对象时将半径初始化为r      
		③ 三个成员方法              
				double getArea( )      //获取圆的面积            
				double getPerimeter( ) //获取圆的周长              
				void  show( )          //将圆的半径、周长、面积输出到屏幕

2. 编写一个圆柱体类Cylinder，它继承于上面的Circle类，还拥有： 
		① 1个成员变量，圆柱体的高；
		② 构造方法           
 				Cylinder (double r, double  h) //创建Circle对象时将半径初始化为r         
		③ 成员方法
				double getVolume( )   //获取圆柱体的体积             
				void  showVolume( )   //将圆柱体的体积输出到屏幕  
			编写应用程序，创建类的对象，分别设置圆的半径、圆柱体的高，
			计算并分别显示圆半径、圆面积、圆周长，圆柱体的体积。 
 */
class Circle
{
    public:
    Circle()
    :radius(0)
    {
       cout<<"circle()"<<endl;
    }
    Circle(double r)
    :radius(r)
    {
        cout<<"circle(double)"<<endl;
    }
    double getArea()
    {
          return pai*radius*radius;
    }
    double getPerimeter()
    {
        return pai*radius*2;

    }
    void show()
    {
          cout<<radius<<endl
             <<getArea()<<endl
             <<getPerimeter()<<endl;
    }

    private:double radius;
};

class Cylinder:public Circle
{

    public:
    Cylinder(double r, double h)
    :Circle(r)
    ,height(h)
    {
        cout<<"cylinder(double , double)"<<endl;
    }
    double getVolume()
    {
          return Circle::getArea()*height;
    } 
    void showVolume()
    {
        cout<<getVolume()<<endl;
         
    }
    private: double height;

};
int main()
{

    Circle c(1);
    c.show();
    Cylinder cl(1,1);
    cl.showVolume();
    

    return 0;
}