#pragma once
const int MAX = 1000;
class StackA
{
public:
	StackA();
	~StackA();
	void push(int item);
	int pop();
	bool isEmpty();
	bool isFull();
	int getTop();
private:
	int top;
	int stack[MAX];
};

