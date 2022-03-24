#include <iostream>
#include <string>
using namespace std;

class arrayStack {
public:
	arrayStack(int capacity);
	bool empty(); 
	int size();
	int top();
	void push(int data);
	void pop();

private:
	int* arr;  // 스택의 원소를 저장하는 배열
	int capacity; // 스택의 최대 크기를 저장하는 변수
	int topIndex; // 배열에서 스택의 top이 저장되어 있는 인덱스를 저장하는 변수
};

arrayStack::arrayStack(int capacity) {
	this->capacity = capacity;
	arr = new int[capacity];
	topIndex = -1;
}

bool arrayStack::empty() {
	if (topIndex == -1) {
		return true;
	}
	else {
		return false;
	}
}

int arrayStack::top() {
	if (empty())
		return -1;
	return arr[topIndex];
}

void arrayStack::push(int data) {
	if (size() == capacity)
	{
		cout << "FULL";
		return;
	}
	
	topIndex++;
	arr[topIndex] = data;
}

int arrayStack::size() {
	return topIndex + 1;
}

void arrayStack::pop() {
	if (empty()) {
		cout << -1 << '\n';
		return;
	}

	cout << top() << '\n';
	topIndex--;
}

int main(void)
{
	int capacity, n;
	cin >> capacity >> n;

	arrayStack s(capacity);

	while (n--)
	{
		string command;
		cin >> command;
		if (command == "size")
		{
			cout << s.size() << endl;
		}
		else if (command == "empty")
		{
			if (s.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}

		else if (command == "top")
		{
			cout << s.top() << endl;
		}
		else if (command == "push")
		{
			int a;
			cin >> a;
			s.push(a);
		}
		else if (command == "pop")
		{
			s.pop();
		}
	}
}