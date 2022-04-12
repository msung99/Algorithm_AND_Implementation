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
	int size();
	bool empty();
	void front();
	void rear();
	void enqueue(int data);
	void dequeue();
};

Queue::Queue(int capacity)
{
	this->capacity = capacity;
	arr = new int[capacity];
	arrSize = 0;
	frontIndex = 0;
	rearIndex = 0;
}

int Queue::size()
{
	return arrSize;
}

bool Queue::empty()
{
	return (arrSize == 0);
}

void Queue::front()
{
	if (empty())
		return;
	else
		cout << arr[frontIndex] << endl;
}

void Queue::rear()
{
	if (empty())
		return;
	else
	{
		if (rearIndex == 0)
		{
			cout << arr[arrSize - 1] << endl;
		}
		else
		{
			cout << arr[rearIndex - 1] << endl;
		}
	}
}

void Queue::enqueue(int data)
{
	if (arrSize == capacity)
	{
		cout << "FULL " << endl;
		return;
	}
	arr[rearIndex] = data;
	rearIndex = (rearIndex + 1) % capacity;
	arrSize++;
}

void Queue::dequeue()
{
	if (empty())
		return;

	frontIndex = (frontIndex + 1) % capacity;
	arrSize--;
}

int main(void)
{
	Queue q(5);
	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		string command;
		cin >> command;
		if (command == "size")
		{
			cout << q.size() << endl;
		}
		else if (command == "empty")
		{
			cout << q.empty() << endl;
		}
		else if (command == "front")
		{
			q.front();
		}
		else if (command == "rear")
		{
			q.rear();
		}
		else if (command == "dequeue")
		{
			q.dequeue();
		}
		else if (command == "enqueue")
		{
			int data;
			cin >> data;
			q.enqueue(data);
		}
	}
}
