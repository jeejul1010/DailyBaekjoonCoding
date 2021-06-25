#pragma once
typedef struct node
{
	int data;
	struct node* next;

}node;

typedef node* nptr;

class QueueP
{
public:
	QueueP();
	~QueueP();
	void add(int item);
	void remove();
	int getFront();
	bool isEmpty();
private:
	nptr rear;
	int count;
};
