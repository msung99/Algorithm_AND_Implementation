#include <iostream>
#include <string>
using namespace std;

struct node {
	node* next;
	int data;
};

class Stack {
private:
	node* topNode;
	int n;
public:
	Stack();
	int size();
	bool empty();
	int top();
	void pop();
	void push(int data);
};

Stack::Stack()
{
	topNode = NULL;
	n = 0;
}

int Stack::size()
{
	return n;
}

bool Stack::empty()
{
	return (n == 0);
}

int Stack::top()
{
	if (empty())
		return 0;
	else
	{
		return topNode->data;
	}
}

void Stack::pop()
{
	if (empty())
		return;
	else
	{
		node* tmp = topNode;
		topNode = topNode->next;
		delete tmp;
		n--;
	}
}

void Stack::push(int data)
{
	node* newNode = new node;
	newNode->data = data;
	newNode->next = topNode;
	topNode = newNode;
	n++;
}

int main(void)
{
	int testCase;
	cin >> testCase;

	Stack s;

	while (testCase--)
	{
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') // 연산자인 경우
			{
				int num1 = s.top();
				s.pop();
				int num2 = s.top();
				s.pop();
				int result = 0;
				if (str[i] == '+')
				{
					result = num1 + num2;
					s.push(result);
				}
				else if (str[i] == '-')
				{
					result = num2 - num1;
					s.push(result);
				}
				else if (str[i] == '*')
				{
					result = num1 * num2;
					s.push(result);
				}
				else if (str[i] == '/')
				{
					result = num2 / num1;
					s.push(result);
				}
			}
			else  // 숫자인 경우
			{
				s.push(str[i]-'0');   // char 형 숫자는 char ‘0’을 빼줌으로써 int로 바꿀 수 있다!!!
			}
		}
		cout << s.top() << endl;  // 테스틐케이스 종료 직전에, 연산의 최종 결과물을 스택에서 
		s.pop();
	}
}
