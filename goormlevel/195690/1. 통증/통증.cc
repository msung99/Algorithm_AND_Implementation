#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	
	int n;
	cin >> n;
	
	int cnt = 0;
	
	while(n >= 14) {
		n -= 14;
		cnt++;
	}
	
	while(n >= 7) {
		n -= 7;
		cnt++;
	}
	
	while(n >=1) {
		n -= 1;
		cnt++;
	}
	
	cout << cnt;
	
	return 0;
}