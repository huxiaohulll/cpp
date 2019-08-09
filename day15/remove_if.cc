#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::remove;
using std::ostream_iterator;

void test0()
{
    vector<int> numbers{5, 3, 1, 2, 66, 7, 1, 66, 8, 9, 66};
    copy(numbers.begin(),numbers.end(),ostream_iterator<int>(cout," "));
    cout<<endl;

}





int main(void)
{
    test0();
   // test1();
    return 0;
}