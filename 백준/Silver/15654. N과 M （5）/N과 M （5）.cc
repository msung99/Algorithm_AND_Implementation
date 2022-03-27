#include <iostream>
#include <algorithm>
using namespace std;

int num_list[10];
int new_list[10];
bool visited[10];
int n, m;

void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << new_list[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!visited[i]) 
		{
			new_list[k] = num_list[i];
			visited[i] = true;
			func(k + 1);
			visited[i] = false;
		}
	}
}


int main(void)
{
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		cin >> num_list[i];

	sort(num_list, num_list + n); // 오름차순 정렬
	
	func(0);
}