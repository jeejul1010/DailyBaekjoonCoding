#include "StackA.h"
#include <iostream>
using namespace std;

StackA::StackA()
{
	top = 0;
}
StackA::~StackA()
{

}
void StackA::push(int item)
{
	if (isFull())
	{
		cout << "Stack is full so you can't push anymore items" << endl;
	}
	else {
		stack[top++] = item;
	}
}
int StackA::pop()
{
	if (isEmpty())
	{
		cout << "There is nothing to pop" << endl;
		return -1;
	}
	else
	{
		return stack[--top];
	}

}
bool StackA::isEmpty()
{
	return top == 0;
}
bool StackA::isFull()
{
	return top == MAX;
}

int StackA::getTop()
{
	return stack[top - 1];
}
