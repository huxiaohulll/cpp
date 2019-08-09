#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;


void display(int & number)
{
  //  ++number;
    cout<<number<<" ";
}

void test0()
{
    vector<int> numbers{1,3,4,5};
    std::for_each(numbers.begin(),numbers.end(),display);

    std::for_each(numbers.begin(),numbers.end(),[&numbers](int number){
        cout<<number<<" ";
    });

    cout<<endl;

    std::copy(numbers.begin(),numbers.end(),ostream_iterator<int>(cout," "));
    cout<<endl;

}


void test1()
{
    //对线形容器进行查找时，要采用的时std::find/std::count
   vector<int> numbers{7, 1, 2, 6, 8, 9, 3, 4, 5};


   auto it = std::find(numbers.begin(),numbers.end(),1);
    if(it==numbers.end())
    {
        cout<<"not found"<<endl;
    }
    else
    {
            
    cout<<"*it2="<<*it<<endl;
       
    }

   	//为了提高查找速度, 可以先排序，再采用二分查找算法进行查找
	//
	//std::sort默认情况下，按升序方式进行排序
	//std::sort(numbers.begin(), numbers.end());
	std::greater<int> gt;
	std::sort(numbers.begin(), numbers.end());
	std::copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
    std::for_each(numbers.begin(),numbers.end(),display);
    cout<<endl;


    //o(logn)
    //指向第一个不小于 值 的 it,这里不懂
    auto it2 = std::lower_bound(numbers.begin(),numbers.end(),8,gt);
    std::for_each(numbers.begin(),numbers.end(),display);

    if(it2==numbers.end())
    {
        cout<<"not found"<<endl;
    }
    else
    {
            
    cout<<"*it2="<<*it2<<endl;
       
    }

}





int main(void)
{
  //  test0();
    test1();
    return 0;
}