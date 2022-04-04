#include <iostream>
#include <string>
using namespace std;

class arrayQueue {
private:
	int* arr;
	int capacity;
	int frontIndex;
	int rearIndex;
	int size;
public:
	arrayQueue(int capacity);
	bool empty();
	int size();
	int front();
	void enqueue(int data);
	void dequeue();
};

arrayQueue::arrayQueue(int capacity)
{
	this->capacity = capacity;
	arr = new int[capacity];
	size = 0;
	frontIndex = 0;
	rearIndex = 0;
}

bool arrayQueue::empty()
{
	if (size() == 0)
		return true;
	else
		return false;
}

bool arrayQueue::size()
{
	return size;
}

int arrayQueue::front()
{
	if (empty())
	{
		cout << "EMPTY" << endl;
		return -1;
	}
	return arr[frontIndex];
}

void arrayQueue::enqueue(int data)
{
	arr[rearIndex] = data;
	rearIndex = (rearIndex + 1) % capacity;
}

void arrayQueue::dequeue()
{
	if (empty())
	{
		cout << "EMPTY" << endl;
		return;
	}
	else
		frontIndex = (frontIndex + 1) % capacity;
}

int main(void)
{
	int testCase;
	cin >> testCase;

	arrayQueue q(100);

	while (testCase--)
	{
		string command;
		cin >> command;
		if (command == "empty")
		{
			cout << q, empty() << endl;
		}
		else if (command == "size")
		{
			cout << q.size() << endl;
		}
		else if (command == "front")
		{
			cout << q.front() << endl;
		}
		else if (command == "enqueue")
		{
			int data;
			cin >> data;
			q.enqueue(data);
		}
		else if (command == "dequeue")
		{
			q.dequeue();
		}
	}
}
