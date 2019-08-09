#include<iostream>
#include<set>
#include<string>

using std::cout;
using std::endl;
using std::set;
using std::string;


template <class Container>
void display(const Container & c)
{
    typename Container::const_iterator cit=c.begin();
    while(cit !=c.end())
    {
        cout<<*cit<<endl;
        ++cit;
    }
    cout<<endl;

}
void test0()
{
    set<int> numbers;
    cout<<"numbers size="<<numbers.size()<<endl;
    numbers.insert(1);
    numbers.insert(2);
    numbers.insert(3);
    display(numbers);

}

void test1()
{
    /*
       1.特性
     */
    //默认升序
    int arr[6]={2,4,6,8,1,3};
    set<int> numbers(arr,arr+6);
    display(numbers);
    //不支持下标运算符，不能用迭代器修改值，可以删除
   // numbers[0]=3;
   set<int>::iterator it=numbers.begin();
   //*it=9;
   numbers.erase(it);
   cout<<"it=="<<*it<<endl;//虽然被删除了，但是it指向的元素还是存在
   it++;
   cout<<"it=="<<*it<<endl;//而且，删除的元素还是可以++ 
   display(numbers);  //所以，erase 是假删除， 只是这个set没有这个元素，实际还是存在的
   /*
     2.添加
    */

   std::pair<set<int>::iterator,bool> ret=numbers.insert(2);
   if(ret.second){
       cout<<"添加成功"<<endl;
       cout<<*ret.first<<endl;
   }else{
       cout<<"已有元素"<<endl;
       cout<<*ret.first<<endl;
   }

   display(numbers);
    /*
     3.查找
    */
    
   if(numbers.count(2)){  //count 返回查找的数量，其实是1
          cout<<"查找该元素成功"<<endl;
   } else{
       cout<<"没有该元素"<<endl;
   }

   auto it2 =numbers.find(3);
   if(it2 == numbers.end())
   {
       cout<<"没有该元素"<<endl;
   }else
   {
        cout<<"查找成功"<<endl;
        cout<<"it2=="<<*it2<<endl;
   }
   

}





int main(void)
{
//    test0();
    test1();
    return 0;
}