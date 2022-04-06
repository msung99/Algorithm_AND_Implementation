#include <iostream>
#include <string>
using namespace std;

class arrayQueue {
private:
	int* arr;
	int frontIndex;
	int rearIndex;
	int n;
	int capacity;
public:
	arrayQueue(int capacity);
	int size();
	bool empty();
	int front();
	int rear();
	void enqueue(int data);
	void dequeue();
};

arrayQueue::arrayQueue(int capacity)
{
	this->capacity = capacity;
	arr = new int[capacity];
	n = frontIndex = rearIndex = 0;
}

int arrayQueue::size()
{
	return n;
}

bool arrayQueue::empty()
{
	return (n == 0);
}

int arrayQueue::front()
{
	if (empty())
	{
		cout << "EMPTY" << endl;
		return -1;
	}
	else
	{
		return arr[frontIndex];
	}
}

int arrayQueue::rear()
{
	if (empty())
	{
		cout << "EMPTY" << endl;
		return -1;
	}
	else
	{
		return arr[rearIndex-1];    // rearIndex는 맨 마지막 원소 인덱스의 다음 인덱스이므로 "진짜 마지막 인덱스"의 원소 값을 출력하기 위해선 rearIndex-1 인덱스의 데이터를 추출해준다.
	}
}

void arrayQueue::enqueue(int data)
{
	if (n > capacity)
	{
		cout << "FULL" << endl;
		return;
	}
	else
	{
		arr[rearIndex] = data;
		rearIndex = (rearIndex + 1) % capacity;
		n++;
	}
}

void arrayQueue::dequeue()
{
	if (empty())
	{
		cout << "EMPTY" << endl;
		return;
	}
	else
	{
		frontIndex = (frontIndex + 1) % capacity;
		n--;
	}
}

int main() {
	int test_case;
	cin >> test_case; // N : 큐의 크기, test_case : 테스트케이스 횟수
	arrayQueue _arr(10000);

	for (int i = 0; i < test_case; i++) {
		string a;
		cin >> a;

		if (a == "isEmpty") {
			if (_arr.empty())
				cout << "True" << endl;
			else
				cout << "False" << endl;
		}

		else if (a == "dequeue") {
			_arr.dequeue();
		}

		else if (a == "enqueue") {
			int v;
			cin >> v;
			_arr.enqueue(v);
		}

		else if (a == "front") {
			cout << _arr.front() << endl;
		}

		else if (a == "rear") {
			cout << _arr.rear() << endl;
		}

		else if (a == "size") {
			cout << _arr.size() << '\n';
		}
	}
}
