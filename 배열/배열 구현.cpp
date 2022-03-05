#include <iostream>
#include <string>
using namespace std;

class Array
{
private:
	int* arr;
	int arrSize;
public:
	Array(int sz)
	{
		this->arrSize = sz;
		this->arr = new int[arrSize];
		for (int i = 0; i < sz; i++)
		{
			arr[i] = 0;
		}
	}

	int at(int idx) //�ش� �ε��� ���
	{
		return arr[idx];
	}

	void add(int idx, int value)
	{
		for (int i = arrSize - 2; i >= idx; i--)
			//�Ǹ����� 2��°���� �Ǹ����� ���� �ֱ����
			//�ش��ε������� �ε���+1���� �ֱ�
		{
			arr[i + 1] = arr[i];
		}
		arr[idx] = value; //�ε��� �� ����
	}

	void set(int idx, int value) //�ܼ��� ���ֱ�
	{
		arr[idx] = value;
	}

	void print()
	{
		for (int i = 0; i < arrSize; i++)

		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void remove(int idx)
	{
		for (int i = idx + 1; i < arrSize; i++)
			//�ε������� �ε���-1���� �ֱ�
		{
			arr[i - 1] = arr[i];
		}
		arr[arrSize - 1] = 0;
	}

	void find(int value)
	{
		int count = 0;
		for (int i = 0; i < arrSize; i ++ )
		{
			if (arr[i] == value)
			{
				count++;
			}		
		}
		cout << count << endl;
	}

	void shift(int idx)
	{
		int number = arr[0];
		for (int i = 0; i < idx; i++)
		{
			for (int i = 0; i < arrSize-1; i++) 
			{
				arr[i] = arr[i+1]
			}
			arr[arrSize - 1] = number;
			number = arr[0];
		}
	}

	void reverse(int idx, int number)
	{
		int a = arr[idx];
		if (number % 2 == 0)
		{
			for (int i = 0; i < number / 2; i++)
			{
				arr[idx + i] = arr[idx + i + number-1];
				arr[idx + i + number - 1] = a;
				a = arr[idx + i + 1];
			}
		}
	}

};

int main()
{
	int number = 0;
	int size = 0;
	string a = "";
	int b = 0;
	int c = 0;
	cin >> number >> size;
	int sample = 0;
	for (int k = 0; k < size; k++)
	{
		cin >> sample;
		ar.set(k, sample);
	}

	Array ar(size);
	for (int i = 0; i < number; i++)
	{
		cin >> a;
		if (a == "print")
		{
			ar.print();
			continue;
		}


		cin >> b;
		if (a == "shift")
		{
			ar.shift(b);
			continue;
		}


		cin >> c;
		if (a == "reverse")
		{
			ar.reverse(b, c);
			continue;
		}
}