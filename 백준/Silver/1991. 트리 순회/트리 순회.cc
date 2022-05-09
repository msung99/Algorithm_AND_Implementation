#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int left_child[27];
int right_child[27];

void pre_order(int cur)
{
	cout << char(cur + 'A' - 1);
	if (left_child[cur] != 0)
		pre_order(left_child[cur]);
	if (right_child[cur] != 0)
		pre_order(right_child[cur]);
}

void in_order(int cur)
{
	if (left_child[cur] != 0)
		in_order(left_child[cur]);
	cout << char(cur + 'A' - 1);
	if (right_child[cur] != 0)
		in_order(right_child[cur]);
}

void post_order(int cur)
{
	if (left_child[cur] != 0)
		post_order(left_child[cur]);
	if (right_child[cur] != 0)
		post_order(right_child[cur]);
	cout << char(cur + 'A' - 1);
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		char cur, left, right;
		cin >> cur >> left >> right;
		if (left != '.')
			left_child[cur - 'A' + 1] = left - 'A' + 1;
		if (right != '.')
			right_child[cur - 'A' + 1] = right - 'A' + 1;
	}
	pre_order(1);
	cout << '\n';
	in_order(1);
	cout << '\n';
	post_order(1);
	cout << '\n';
}