#include<iostream>
using namespace std;
class CircularQueue
{
private:
	int front;
	int rear;
	int* items;
	int size;
public:
	CircularQueue()
	{
		size = 100109;
		front = -1;
		rear = -1;
		items = new int[size];
	}
	bool enqueue(int element)
	{
		if ((front == 0 && rear == size-1 )|| (rear == (front - 1) % (size - 1)))//to check whether queue is full
		{
			cout << "Queue is full";
			return false;
		}
		else if (front == -1)// first element to push
		{
			front = rear = 0;
			items[rear] = element;
		}
		else if (rear == size - 1 && front != 0)//to maintain cyclic nature
		{
			rear = 0;
			items[rear] = element;
		}
		else//normal flow
		{
			rear++;
			items[rear] = element;
		}
	}
	int dequeue()
	{
		if (front == -1)// to  check queue is empty
		{
			cout << "Queue is Empty";
			return -1;

		}
		int ans = items[front];
		items[front] = -1;
	    if (front == rear)// single element is present
		{
			cout << "Queue is Empty";
			return -1;

		}
		if (front == size - 1)//to maintain cyclic nature
		{
			front = 0; 
	    }
		
		 else
		 {
			 front++;
		 }
		return front;
	}
	
}; int main()
{
	CircularQueue Q;
	Q.enqueue(1);
	Q.enqueue(1);
	Q.enqueue(1);

	Q.enqueue(1);
	Q.dequeue();

	return 0;
}