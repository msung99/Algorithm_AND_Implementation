#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	int items[3] = {14, 7, 1};
	int cnt = 0;
	for(int item : items) {
		cnt += n / item;
		n %= item;
	}
	cout << cnt;
	
	return 0;
}