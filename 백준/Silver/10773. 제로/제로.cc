#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	int k;
	int sum = 0;
	int a;
	stack<int> st;

	cin >> k;
	while (k--)
	{
		cin >> a;
		if (a == 0)
		{
			st.pop();
		}
		else
		{
			st.push(a);
		}
	}

	int b = st.size();
	while (b--)
	{
		sum += st.top();
		st.pop();
	}
	cout << sum << '\n';
}