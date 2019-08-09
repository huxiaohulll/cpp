#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

//类模板,队列 ，先进先出
template <class T, int kSize = 10>
class Queue
{
public:
	Queue()
	: _(-1)
	, _data(new T[kSize]())
	{}

	~Queue();

	bool full() const;
	bool empty() const;
	void push(const T & t);
	void pop();
	T & top() const;

private:
	int _head;
    int _tail;
	T * _data;
};

template <class T, int kSize>
Queue<T, kSize>::~Queue()
{
	if(_data)
		delete [] _data;
}


template <class T, int kSize>
bool Queue<T, kSize>::full() const
{
	return _tail-_head == kSize - 1;
}

template <class T, int kSize>
bool Stack<T, kSize>::empty() const
{
	return _top == -1;
}

template <class T, int kSize>
void Stack<T, kSize>::push(const T & t)
{
	if(!full()) {
		_data[++_top] = t;
	} else {
		//LogInfo();
		cout << "stack is full, cannot push any more data!" << endl;
	}
}

template <class T, int kSize>
void Stack<T, kSize>::pop()
{
	if(!empty()) {
		--_top;
	} else {
		cout << "stack is empty, no more data!" << endl;
	}
}

template <class T, int kSize>
T & Stack<T, kSize>::top() const
{
	return _data[_top];
}

void test0()
{
	Stack<int> stack;
	cout << "此时栈中是否为空?" << stack.empty() << endl;
	stack.push(1);
	cout << "此时栈中是否为空?" << stack.empty() << endl;

	for(int idx = 2; idx != 12; ++idx) {
		stack.push(idx);
	}
	cout << "此时栈中是否已满?" << stack.full() << endl;

	while(!stack.empty()) {
		cout << stack.top() << endl;
		stack.pop();
	}
	cout << "此时栈中是否为空?" << stack.empty() << endl;
}
 
void test1()
{
	//vector<int> numbers;//   实例化
	Stack<string> stack;//类模板 ==》 模板类
	cout << "此时栈中是否为空?" << stack.empty() << endl;
	stack.push("aaa");
	cout << "此时栈中是否为空?" << stack.empty() << endl;

	for(int idx = 1; idx != 11; ++idx) {
		stack.push(string(3, 'a' + idx));
	}
	cout << "此时栈中是否已满?" << stack.full() << endl;

	while(!stack.empty()) {
		cout << stack.top() << endl;
		stack.pop();
	}
	cout << "此时栈中是否为空?" << stack.empty() << endl;
}
int main(void)
{
	//test0();
	test1();
 
	return 0;
}
