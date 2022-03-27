#include <iostream>
using namespace std;

int num_list[10];
bool visited[10];
int n, m;

void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << num_list[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		num_list[k] = i;
		func(k + 1);
	}
}


int main(void)
{
	cin >> n >> m;
	func(0);
}