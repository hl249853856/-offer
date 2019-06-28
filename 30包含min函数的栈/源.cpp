#include<iostream>
#include<stack>
using namespace std;

template<typename T> class StackWithMin
{
public:
	void push(const T& value);
	void pop();
	const T& min();
private:
	stack<T> Data;
	stack<T> Min;
};

template<typename T>
void StackWithMin<T>::push(const T& value)
{
	Data.push(value);

	if (Min.size() == 0 || value < Min.top())
		Min.push(value);
	else
		Min.push(Min.top());
}

template<typename T>
void StackWithMin<T>::pop()
{
	if (!Data.empty()&&!Min.empty())
	{
		Data.pop();
		Min.pop();
	}	
}

template<typename T>
const T& StackWithMin<T>::min()
{
	if (!Data.empty() && Min.empty())
		return Min.top();
}