#include <math.h>
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::multimap;
using std::string;
using std::pair;

/*
关键字不能相同
默认升序
底层红黑，查找logn

 */
template<class Container>
void display(const Container &c)
{
    typename Container::const_iterator cit=c.begin();
    for(;cit!=c.end();cit++)
    {
        cout<<cit->first<<"---->"<<cit->second<<endl;
    }
}
void test0()
{
    multimap<int,string> stus;
    stus.insert(pair<int,string>(1,"huhu"));
    stus.insert(pair<int,string>(2,"toto"));
    stus.insert(pair<int,string>(3,"pepe"));
    stus.insert(pair<int,string>(4,"yuyu"));
    display(stus);


}

void test1()
{

    multimap<int,string> stus={
        std::make_pair(3,"pepe"),
        pair<int,string>(1,"huhu"),
        std::make_pair(2,"toto"),
        std::make_pair(4,"yuyu"),
    };
    display(stus);
    //multimap和multiset一样，无须判断放入成功
    auto
    ret=stus.insert(std::make_pair(0,"lele"));
    cout<<ret->first<<"---->"<<ret->second<<endl;
  
       display(stus);
    //  multimap不支持下标运算
     
    //查找元素
    multimap<int, string>::iterator it = stus.find(2);
	if(it != stus.end()) {
		cout << "查找元素成功" << endl;
		cout << it->first << " ---> " << it->second << endl;
	} else {
		cout << "查找失败, 不会添加新的元素" << endl;
	}
	display(stus);

    auto it2=stus.count(8);
    if(it2)
    {
        cout<<"successful"<<endl;
        
    }
    else
    {
        cout<<"fail"<<endl;
    }
    


}


void test2()
{

    multimap<string,string> stus={
        std::make_pair("001","pepe"),
        pair<string,string>("002","huhu"),
        std::make_pair("003","toto"),
        std::make_pair("004","yuyu"),
    };
    display(stus);
    auto
    ret=stus.insert(std::make_pair("005","lele"));

        cout<<ret->first<<"---->"<<ret->second<<endl;
  
       display(stus);
    
    //查找元素
    multimap<string, string>::iterator it = stus.find("006");
	if(it != stus.end()) {
		cout << "查找元素成功" << endl;
		cout << it->first << " ---> " << it->second << endl;
	} else {
		cout << "查找失败, 不会添加新的元素" << endl;
	}
	display(stus);

    auto it2=stus.count("000");
    if(it2)
    {
        cout<<"successful"<<endl;
        
    }
    else
    {
        cout<<"fail"<<endl;
    }
    


}


class Point
{
public:
	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int,int)" << endl;}

	double getDistance() const
	{
		return sqrt(_ix * _ix + _iy * _iy);
	}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}

bool operator<(const Point & lhs, const Point & rhs)
{
	return lhs.getDistance() < rhs.getDistance();
}


bool operator>(const Point & lhs, const Point & rhs)
{
	return lhs.getDistance() > rhs.getDistance();
}

struct Comparator
{
	bool operator()(const Point & lhs, const Point & rhs) const
	{
		return lhs.getDistance() > rhs.getDistance();
	}
};




//multimap中使用自定义类创建默认升序，同样必须重载小于号,类似set的自定义类的使用
void test3()
{
    //	multimap<Point, int> points =
   // multimap<Point, int,Comparator> points =
      multimap<Point, int,std::greater<Point> >points =
	{
		std::make_pair(Point(1, 2), 1),
		std::make_pair(Point(2, 2), 1),
		std::make_pair(Point(3, 2), 1),
		std::make_pair(Point(4, 2), 1),
	};

	display(points);

}


int main(void)
{
 //   test0();
  //  test1();
   test2();
 test3();
}