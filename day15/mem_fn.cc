#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using std::cout;
using std::endl;
using std::mem_fn;
using std::vector;

class Number
{
    public:
        Number(int data)
        :_data(data)
        {}

        void display() const{
            cout<<_data<<" ";
        }

        bool isEven() const{
            return (_data % 2==0);
        }

        bool isPrime() const{
            if(_data ==1 || _data==0)
                return false;
            for(int idx=2;idx <)
        }
    private:int _data;
}