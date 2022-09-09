#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(void)
{
	deque<int> dq;
	int testCase;

	cin >> testCase;
	while (testCase--)
	{
		deque<int> dq;
		string command, data;
		int size;
		bool isReverse = false; // R 명령어를 입력받았는지 여부를 체크히는 변수
		bool isError = false; // 에러가 발생했는지 여부를 체크하는 변수

		cin >> command;
		cin >> size;
		cin >> data;
		string storage_num = ""; // 숫자를 임시 저장하는 문자열. 

		// 문자열 data 에서 숫자만 따로 추출해서 덱에다 저장하기
		for (int i = 0; i < data.size(); i++)
		{
			if (data[i] == '[')
				continue;
			else if ('0' <= data[i] && '9' >= data[i]) // 숫자인 경우
			{
				storage_num += data[i]; // 숫자를 임시저장. 숫자가 1의 자리가 아닐 수도 있으므로
				// 기호 ',' 이나 ']' 을 만나기전까지 숫자를 계속 만들어나간다. 예를들어 숫자 42를 data에서 읽어올때 stoarge_num 에다 4를 저장하고 , 2를 저장하고, 쉼표 기호 ',' 또는  기호 ']'
				// 를 만나면 stoarge_num 에 읽어들인 숫자를 기반으로 숫자 42를 생성하고 덱에다 저장한다.
			}
			else if ((data[i] == ',' || data[i] == ']') && storage_num != "")
			{   // c_str : string 객체를 char로 변환해서 리턴   => atoi() 는 char형을 int형으로 바꾸는 것이므로, atoi() 를 적용하기 전에 c_str 로 string형을 char형으로 변환해준다.
				dq.push_back(atoi(storage_num.c_str())); // 숫자 문자열을 int형으로 변환해서 덱에다 저장
				storage_num = ""; // 다음 for문을 돌면서 숫자를 또 stoarge_num 에 새롭게 저장하기 위해 비어줌
			}
		}

		// 명렁어에 대한 처리
		for (int i = 0; i < command.size(); i++)
		{
			if (command[i] == 'R') // 실제로 덱의 원소들을 뒤집지 않고, bool형 자료형으로 덱을 뒤집어야 하는지 마는지 체크 표시만 해준다. 
			{
				isReverse = !isReverse;
			}
			else if (command[i] == 'D')
			{
				if (dq.empty()) // 비어있는 덱에서 원소를 추출하려는 경우 에러 발생
				{
					isError = true; // 에러
					break;
				}

				// 뒤집어야 하는경우(즉, isReverse = true 인 경우) 덱의 맨 뒤에서 부터 원소를 제거해나가면 
				// 뒤집어져 있는 덱에서 앞에 있는 원소부터 제거하는 것과 동일한 상황이 된다.
				// ( ex. [1,2,3,4] 를 뒤집으면 [4,3,2,1] 인데 명령어 D 를 수행하면 [3,2,1] 이 아닌가? 그런데 실제로 뒤집지 않고 [1,2,3,4] 에 대해서 끝 원소를 제거하면 [1,2,3] 이 되어서
				// 결론적으로 4 라는 원소가 제거된 것은 동일하게 나온다.
				
				// => 즉, 덱의 원소를 뒤집고 pop_front 를 하는것과, 그냥 덱을 뒤집지 않고 원소를 pop_back 하는 것은 동일한 상황이다! 
			
				if (isReverse)
				{
					dq.pop_back();
				}
				else
				{
					dq.pop_front();
				}
			}
		}

		// 덱의 원소들을 출력
		if (isError)
		{
			cout << "error\n";
		}
		else if (dq.empty())
		{
			cout << "[]\n";
		}
		else if (isReverse) // 역순으로 덱을 출력해야하는 경우
		{
			cout << "[";
			while (dq.size() > 1)
			{
				cout << dq.back() << ',';
				dq.pop_back();
			}
			// dq.size() == 1 일때, 즉 덱에 원소가 하나 남은경우는 따로처리
			cout << dq.back() << "]\n"; // dq 사이즈가 1일때도 while 문 안에서 출력할 내용을 처리하면 
										// "[1,2,3,4]" 가 출력되지 않고 맨 뒤에 쉼표가 붙어서 "[1,2,3,4,]" 가 출력됨 
		}
		else // 그냥 출력하면 되는 경우
		{
			cout << "[";
			while (dq.size() > 1)
			{
				cout << dq.front() << ",";
				dq.pop_front();
			}
			cout << dq.front() << "]\n";
		}
	}
}

/*
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	while (n--) {
		deque<int> dq;
		string command, str;
		int size;
		cin >> command >> size >> str;

		// deque 원소 구성
		int num = 0; // dq 에 push 되는 숫자
		int multi = 1; // 곱해지는 수 (자릿수를 고려하기 위함)
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != '[' && str[i] != ']' && str[i] != ',') {
				//cout << "num:" << num << endl;
				num = num + ((str[i] - '0') * multi);
				multi *= 10;

				if (str[i + 1] == ']' || str[i + 1] == ',') {
					dq.push_back(num);
					num = 0;
					multi = 1;
				}
			}
		}
	
		for (int i = 0; i < command.size(); i++) {
			if (command[i] == 'R') {
				int size = dq.size();
				for (int j = 0; j < size/2; j++) {
					//iter_swap(dq.begin(), dq.begin() + size -1 - j);
					swap(dq[j], dq[size-1-j]);
				}
			}

			else if (command[i] == 'D') {
				if (dq.empty()) {
					cout << "error\n";
					break;
				}
				dq.pop_front();
			}
		}

		if (dq.empty()) {
			cout << "[]";
			continue;
		}

		cout << "[";
		for (int i = 0; i < dq.size()-1; i++) {
			cout << dq[i] << ',';
		}
		cout << dq[dq.size()-1] << "]\n";
	}
}
*/
