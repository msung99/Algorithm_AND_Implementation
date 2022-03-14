#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> s;
	int n;
	cin >> n;
	int count;
	int t = 1; // 
	string res;

	while (n--) // n개의 숫자에 대해 실행
	{
		cin >> count; 
		while (t <= count) // count 까지 오름차순으로 숫자를 push 
		{
			s.push(t);
			t++;
			res += "+\n";
		}
		if (s.top() != count)  
		{
			cout << "NO\n";
			return 0;
		}
		s.pop();
		res += "-\n";
	}
	cout << res;
}