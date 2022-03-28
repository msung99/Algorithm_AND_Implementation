#include <iostream>
#include <algorithm>
using namespace std;

int arr[15];  // 배열 num의 원소들의 인덱스를 저장하는 배열
int num[15]; // 실제 데이터가 저장되는 배열
int visited[15];
int n;

void func(int k)
{
	if (k == 6)
	{
		int check = true;
		int prev = -1;
		for (int i = 0; i < 6; i++)
		{
			if (prev > num[arr[i]])
				check = false;
			prev = num[arr[i]];
		}

		if (check)
		{
			for (int i = 0; i < 6; i++)
				cout << num[arr[i]] << ' ';
			cout << '\n';
		}
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			arr[k] = i;
			visited[i] = true;
			func(k + 1);
			visited[i] = false;
		}
	}
}


int main(void)
{

	while (1)
	{
		cin >> n;
		if (n == 0)
			break;

		for (int i = 0; i < n; i++)
			cin >> num[i];
		
		sort(num, num + n);

		func(0);
		 cout << '\n';

		fill(arr, arr + n, 0);
		fill(num, num + n, 0);
	}
}