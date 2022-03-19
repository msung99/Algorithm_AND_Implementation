#include <iostream>
#include <string>
using namespace std;

class arrayStack {
private:
	int* arr; // 스택의 원소를 저장하는 배열
	int capacity; // 스택의 최대 크기를 저장하는 변수 
	int topIndex; // 배열에서 스택의 top이 저장되어 있는 인덱스를 저장하는 변수
public:
	arrayStack(int capacity);
	bool empty();
	int size();
	int top();
	void push(int data);
	void pop();
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

int arrayStack::size() {
	return topIndex + 1;
}

int arrayStack::top() {
	if (empty()) {
		return -1;
	}
	return arr[topIndex];
}

void arrayStack::push(int data) {
	if (size() == capacity) {
		cout << "FULL\n";
		return;
	}
	topIndex++;
	arr[topIndex] = data;
}

void arrayStack::pop() {
	if (empty()) {
		cout << "-1\n";
	}
	else {
		cout << top() << "\n";
		topIndex--;
	}
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
		if (command == "top")
		{
			cout << s.top() << "\n";
		}
		else if (command == "size")
		{
			cout << s.size() << "\n";
		}
		else if (command == "empty")
		{
			if (s.empty())
				cout << "1\n";
			else
				cout << "0\n";
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
