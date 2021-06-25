#include <iostream>
#include "QueueP.h"
#include "stddef.h"

using namespace std;

QueueP::QueueP() {
	rear = NULL;
	count = 0;
}

QueueP::~QueueP()
{
	while (!isEmpty())
	{
		remove();
	}

}

void QueueP::add(int item)
{
	nptr temp = new node;
	temp->data = item;

	if (isEmpty())
	{
		temp->next = temp;
	}
	else
	{
		temp->next = rear->next;
		rear->next = temp;
	}
	rear = temp;
	count++;
}

void QueueP::remove()
{
	if (isEmpty())
	{
		cout << "There is nothing to remove!" << endl;
	}
	else
	{
		if (count == 1)
		{
			delete rear;
			rear = NULL;
		}
		else {
			nptr front = rear->next;
			rear->next = front->next;
			delete front;
			front = rear->next;
		}
		count--;
	}
}

bool QueueP::isEmpty() {
	return rear == NULL;
}

int QueueP::getFront() {
	nptr front = rear->next;
	return front->data;
}