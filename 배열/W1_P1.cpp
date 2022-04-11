#include <iostream>
#include <string>
using namespace std;

class Array {
private:
	int* arr;
	int arrSize;
public:
	Array(int arrSize);
	void add(int idx, int data);
	void remove(int idx);
	void set(int idx, int data);
	void print();
	void find(int data);
};

Array::Array(int arrSize)
{
	this->arrSize = arrSize;
	this->arr = new int[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = 0;
	}
}

void Array::add(int idx, int data)
{
	for (int i = arrSize - 2; i >= idx; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[idx] = data;
}

void Array::remove(int idx)
{
	for (int i = idx + 1; i <= arrSize - 1; i++)
	{
		arr[i - 1] = arr[i];
	}
	arr[arrSize - 1] = 0;
}

void Array::set(int idx, int data)
{
	arr[idx] = data;
}

void Array::print()
{
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void Array::find(int data)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] == data)
		{
			cout << i << endl;
			return;
		}
	}
	cout << -1 << endl;
}

int main(void)
{
	int testCase, arrSize;
	cin >> testCase >> arrSize;

	Array arr(arrSize);

	while (testCase--)
	{
		string command;
		cin >> command;
		if (command == "add")
		{
			int idx, data;
			cin >> idx >> data;
			arr.add(idx, data);
		}
		else if (command == "remove")
		{
			int idx;
			cin >> idx;
			arr.remove(idx);
		}
		else if (command == "set")
		{
			int idx, data;
			cin >> idx >> data;
			arr.set(idx, data);
		}
		else if (command == "print")
		{
			arr.print();
		}
		else if (command == "find")
		{
			int data;
			cin >> data;
			arr.find(data);
		}
	}
}