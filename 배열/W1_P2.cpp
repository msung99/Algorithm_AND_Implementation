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
	void print();
	void left_shift(int count);
	void right_shift(int count);
	void reverse(int idx1, int number);
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

// 좌측연산 쉬프트
void Array::left_shift(int count) 
{
	int front_number = arr[0]; // 배열의 맨 앞 인덱스의 숫자

	for (int k = 0; k < count; k++)
	{
		for (int i = 1; i <= arrSize - 1; i++)
		{
			arr[i-1] = arr[i];
		}
		arr[arrSize - 1] = front_number;
		front_number = arr[0];
	}
}

// 우측연산 쉬프트
void Array::right_shift(int count)
{
	int last_number = arr[arrSize-1]; // 배열의 맨 마지막 인덱스의 숫자

	for (int k = 0; k < count; k++)
	{
		for (int i = arrSize - 2; i >= 0; i--)
		{
			arr[i + 1] = arr[i];
		}
		arr[0] = last_number;
		last_number = arr[arrSize - 1];
	}
}

// 인덱스 idx ~ number 까지의 숫자를 뒤집기
void Array::reverse(int idx1, int  idx2)
{
	int* result = new int[arrSize];
	for (int i = 0; i < arrSize; i++) // 배열의 복사본 result 를 만든다
	{
		result[i] = arr[i];
	}

	for (int i = 0; i <= idx2-idx1; i++)  // 인덱스 idx1 ~ idx2의 원소들을 뒤집으면서 배열 result에 할당
	{
		result[idx1 + i] = arr[idx2 - i];
	}
	arr = result;
}

void Array::print()
{
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}


int main(void)
{
	int testCase, arrSize;
	cin >> testCase >> arrSize;


	Array arr(arrSize);
	int data;
	for (int i = 0; i < arrSize; i++)
	{
		cin >> data;
		arr.add(i, data);
	}

	while (testCase--)
	{
		string command;
		cin >> command;
		if (command == "shift")
		{
			int count;
			cin >> count;
			arr.left_shift(count);
		}
		else if (command == "print")
		{
			arr.print();
		}
		else if (command == "reverse")
		{
			int idx1, idx2;
			cin >> idx1 >> idx2;
			arr.reverse(idx1, idx2);
		}
	}
}
