#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Figure
{
public :
    virtual void display() const=0;
    virtual double area() const=0;
};

void display(Figure * fig)
{
    fig->display();
    cout<<"的面积是："<<fig->area()<<endl;

}

class Rectangle
:public Figure
{
public:
    Rectangle(double length,double width)
    :_length(length)
    ,_width(width)
    {
        cout<<"Rectangle()"<<endl;

    }

    void display() const
    {
        cout<<"retangle"<<endl;
    }
    double area() const
    {
        return _length*_width;
    }
private:
    double _length;
    double _width;

};

int main(void)
{
    Rectangle rectangle(3,4);
    rectangle.display();
    cout<<rectangle.area()<<endl;
}
