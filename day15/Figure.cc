#include <math.h>
#include <functional>
#include <iostream>
using std::cout;
using std::endl;


class Figure
{
    public :
        using DisplayCallback = std::function<void()>;
        using AreaCallback = std::function<double()>;
        void setDisplayCallback(const DisplayCallback &cb)
        {
            _displayCb =cb;
        }
        void setAreaCallback(const AreaCallback &ac)
        {
            _areaCb=ac;
        }
        void handleDisplayCallback()
        {
            if(_displayCb)
            {
                _displayCb();
            }
        }

        double handleAreaCallback()
        {
            if(_areaCb)
                return _areaCb();
            else
            {
                return 0;
            }
            
        }
       



    private :
        DisplayCallback _displayCb;
        AreaCallback _areaCb;

};

class Circle
{
public:
	Circle(double radius)
	: _radius(radius)
	{
		cout << "Circle()" << endl;
	}

	void print() const
	{	cout << "circle";	}

	double calcArea() const
	{
		return 3.14159 * _radius * _radius;
	}

private:
	double _radius;
};

class Triangle
{
public:
	Triangle(double a, double b, double c)
	: _a(a)
	, _b(b)
	, _c(c)
	{
		cout << "Triangle()" << endl;
	}

	void show() const
	{
		cout << "triangle";
	}

	double getArea() const
	{
		double p = (_a + _b + _c)/2;
		return sqrt(p * (p - _a) * (p - _b) * (p - _c));
	}

private:
	double _a;
	double _b;
	double _c;
};


class Rectangle
{
    public:
        Rectangle(double length,double width)
        :_length(length)
        ,_width(width)
        {
            cout<<"rectangle()"<<endl;
        }


        void display() const{
            cout<<"rectangle"<<endl;
        }

        double area() const{
            return _length*_width;
        }
    private:
        double _length;
        double _width;
};



class Cube
{
public:
	Cube(double a)
	: _a(a)
	{
		cout << "Cube()" << endl;
	}

	void display() const
	{	cout << "cube";}

	double area() const
	{
		return 6 * _a * _a;
	}

private:
	double _a;
};


int main()
{
    Figure figure;
   // Rectangle rectangle(2,3);
    Circle circle(10);
	Triangle triangle(3, 4, 5);

    //function 封装的类里面的函数的时候，必须使用std::bind

    figure.setDisplayCallback(std::bind(&Circle::print,&circle));
    figure.setAreaCallback(std::bind(&Circle::calcArea,&circle));
    figure.handleDisplayCallback();
    cout<< figure.handleAreaCallback()<<endl;


    figure.setDisplayCallback(std::bind(&Triangle::show,&triangle));
    figure.setAreaCallback(std::bind(&Triangle::getArea,&triangle));
    figure.handleDisplayCallback();
    cout<< figure.handleAreaCallback()<<endl;


    
    return 0;
}