#include<math.h>
#include<iostream>
#include<set>
#include<string>

using std::cout;
using std::endl;
using std::multiset;
using std::string;



template <class Container>
void display(const Container & c)
{
    typename Container::const_iterator cit=c.begin();
    while(cit !=c.end())
    {
        cout<<*cit<<" ";
        ++cit;
    }
    cout<<endl;

}

void test0()
{
    multiset<int> numbers;
    cout<<"numbers size="<<numbers.size()<<endl;
    numbers.insert(1);
    numbers.insert(2);
    numbers.insert(2);
    numbers.insert(3);
    display(numbers);

}
//multiset 可以放重复元素/添加时无须判断是否添加成功/范围查找  剩下的和set保持一致
void test1()
{
    int arr[5]={5,4,3,2,2};
    multiset<int> numbers(arr,arr+5);
    display(numbers);

    auto ret= numbers.insert(1);
    cout<<*ret<<endl;
    display(numbers);

    auto lowerbound= numbers.lower_bound(2);
    auto upperbound=numbers.upper_bound(2);

    cout<<*lowerbound<<endl;
    cout<<*upperbound<<endl;
    while(lowerbound!=upperbound)
    {
        cout<<*lowerbound<<" ";
        lowerbound++;
    }
    cout<<endl;
    
    
}

/*   自定义类 */
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

void test2()//pair的用法
{
    std::pair<int,string> p(1,"深圳");
    cout<<p.first<<"--->"<<p.second<<endl;

}

bool operator<(const Point & lhs, const Point & rhs)
{
	return lhs.getDistance() < rhs.getDistance();
}

bool operator>(const Point & lhs, const Point & rhs)
{
	return lhs.getDistance() > rhs.getDistance();
}

struct Comparator//从小到大 
{
    bool operator()(const Point & lhs, const Point & rhs)
{
	return lhs.getDistance() <rhs.getDistance();
    //return lhs.getDistance() >rhs.getDistance();  降序
}
    
};

void test3()
{
    //multiset<Point,std::greater<Point>> numbers{ //重载大于
   //   multiset<Point,Comparator> numbers{  //升序或降序 
        multiset<Point> numbers{  //默认升序，必须重载小于
        Point(1, 2),
		Point(2, 5),
		Point(-2, 10),
		Point(2, 2),
		Point(2, 2),
		Point(3, 2),

    };

    display(numbers);

     //和内置类型操作相同
    multiset<Point>::iterator it = numbers.begin();
	cout << "*it = " << *it << endl;
	//numbers.erase(it);//可以删除
	display(numbers);

	//添加元素:
	auto ret = numbers.insert(Point(11, 12));
		cout << *ret << endl;

	

#if 1
	//查找元素:
	if(numbers.count(Point(11, 12))) {
		cout << "查找元素成功！" << endl;
	} else {
		cout << "multiset没有该元素" << endl;
	}

	auto it2 = numbers.find(Point(11, 12));
	if(it2 == numbers.end()) {
		cout << "multiset没有该元素" << endl;
	} else {
		cout << "查找元素成功！" << endl;
		cout << "*it2 = " << *it2 << endl;
	}
#endif
}







int main(void)
{
 //   test0();
    test3();
    return 0;
}