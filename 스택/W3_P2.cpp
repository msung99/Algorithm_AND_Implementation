// 중위 표기법을 후위 표기식으로 나타내기
// 1. 피연산자를 만나면 바로 출력한다
// 2. 연산자를 만나면 필요한 만큼의 피연산자를 스택에서 pop하여 연산하고, 연산결과를 다시 스택에 push한다
// 3. 수식이 끝나면, 마지막으로 스택에서 pop하여 출력한다

#include <iostream>
#include <string>
using namespace std;

class arrayStack {
public:
	arrayStack(int capacity);
	bool empty();
	int size();
	char top();
	void push(char data);
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

char arrayStack::top() {
	return char(arr[topIndex]);
}

void arrayStack::push(char data) {
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
		return;
	}

	cout << top();
	topIndex--;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;

	arrayStack s(1000);

	// 1-2+3 
	// 정상 :  12-3+
	// 실제 :  1-2343


	// 12-3+
	// 스택:+
	while (n--)
	{
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++) 
		{
			if (str[i] == '+' || str[i] == '-')
			{
				while (!s.empty())
				{
					s.pop(); 
				}
				s.push(str[i]);
			}
			else if (str[i] == '*' || str[i] == '/')
			{
				while (s.top() == '*' || s.top() == '/')
				{
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
			s.pop();
		cout << '\n';
	}
}
