#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
	int* arr;
	int arrSize;
	int capacity;
	int frontIndex;
	int rearIndex;
public:
	Queue(int capacity);
	void size();
	bool empty();
	void front();
	void rear();
	void enqueue(int data);
	void dequeue();
};

Queue::Queue(int capacity)
{
	this->capacity = capacity;
	arrSize = 0;
	frontIndex = 0;
	rearIndex = 0;
	arr = new int[capacity];
}

void Queue::size()
{
	cout << arrSize << endl;
}

bool Queue::empty()
{
	return (arrSize == 0);
}

void Queue::front()
{
	if (empty())
	{
		cout << "Empty" << endl;
		return;
	}
	cout << arr[frontIndex] << endl;
}

void Queue::rear()
{
	if (empty())
	{
		cout << "Empty" << endl;
		return;
	}
	else
	{
		cout << arr[rearIndex - 1] << endl;
	}
}

void Queue::enqueue(int data)
{
	if (arrSize == capacity)
	{
		cout << "FULL" << endl;
		return;
	}

	arr[rearIndex] = data;
	rearIndex = (rearIndex + 1) % capacity;
	arrSize++;
}

void Queue::dequeue()
{
	if (empty())
	{
		cout << "Empty" << endl;
		return;
	}
	front();
	frontIndex = (frontIndex + 1) % capacity;
	arrSize--;
}

int main(void)
{
	int size, t;
	cin >> size >> t;
	Queue q(size);
	while (t--)
	{
		string a;
		cin >> a;
		if (a == "isEmpty")
		{
			if (q.empty())
				cout << "True" << endl;
			else
				cout << "False" << endl;
		}
		else if (a == "size")
		{
			q.size();
		}
		else if (a == "front")
		{
			q.front();
		}
		else if (a == "rear")
		{
			q.rear();
		}
		else if (a == "enqueue")
		{
			int data;
			cin >> data;
			q.enqueue(data);
		}
		else if (a == "dequeue")
		{
			q.dequeue();
		}
	}
}

