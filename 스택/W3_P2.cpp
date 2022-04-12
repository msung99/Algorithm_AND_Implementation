// 중위 표기법을 후위 표기식으로 나타내기
// 1. 피연산자를 만나면 바로 출력한다
// 2. 연산자를 만나면 필요한 만큼의 피연산자를 스택에서 pop하여 연산하고, 연산결과를 다시 스택에 push한다
// 3. 수식이 끝나면, 마지막으로 스택에서 pop하여 출력한다

#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
	char* arr;
	int capacity;
	int topIndex;
public:
	Stack(int capacity);
	void push(char data);
	char top();
	void pop();
	int size();
	bool empty();
};

Stack::Stack(int capacity)
{
	this->capacity = capacity;
	arr = new char[capacity];
	topIndex = -1;
}

bool Stack::empty()
{
	return (topIndex == -1);
}

int Stack::size()
{
	return topIndex + 1;
}

void Stack::pop()
{
	if (empty())
		return;
	topIndex = topIndex - 1;
}

char Stack::top()
{
	if (empty())
		return -1;

	return arr[topIndex];
}

void Stack::push(char data)
{
	arr[topIndex + 1] = data;
	topIndex++;
}

int main(void)
{
	Stack s(1000);
	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '+' || str[i] == '-')
			{
				while (!s.empty())
				{
					cout << s.top();
					s.pop();
				}
				s.push(str[i]);
			}
			else if (str[i] == '*' || str[i] == '/')
			{
				while (s.top() == '*' || s.top() == '/')
				{
					cout << s.top();
					s.pop();
				}
				s.push(str[i]);
			}
			else
			{
				cout << str[i];
			}
		}
		while (!s.empty())
		{
			cout << s.top();
			s.pop();
		}
		cout << endl;
	}
}
