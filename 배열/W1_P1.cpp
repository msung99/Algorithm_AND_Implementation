#include <iostream>
#include <string>
using namespace std;

class Array {
private:
	int arrSize;
	int* arr;
public:
	Array(int capacity);
	void add(int idx, int data);
	void remove(int idx);
	void set(int idx, int data);
	void print();
	int find(int data);
};

Array::Array(int capacity)
{
	arrSize = capacity;
	arr = new int[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = 0;
	}
}

void Array::add(int idx, int data)
{
	for (int i = arrSize-2; i>=idx; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[idx] = data;
}

void Array::remove(int idx)
{
	for (int i = idx + 1; i <= arrSize -1; i++)
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

int Array::find(int data)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (data == arr[i])
			return i;
	}
	return -1;
}

int main(void)
{
	int testCase, size;
	cin >> testCase >> size;
	Array arr(size);

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
		else if (command == "print")
		{
			arr.print();
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
		else if (command == "find")
		{
			int data;
			cin >> data;
			cout << arr.find(data) << endl;
		}
	}
}
