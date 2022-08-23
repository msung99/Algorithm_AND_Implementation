#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	stack<int> s;
	int n;
	cin >> n;
	while (n--) {
		int data;
		cin >> data;
		if (data == 0)
			s.pop();
		else
			s.push(data);
	}

	int res = 0;
	while (!s.empty()) {
		res += s.top();
		s.pop();
	}
	cout << res;
}