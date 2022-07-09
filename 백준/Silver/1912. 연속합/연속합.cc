#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int s[100005];
int d[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	// 테이블 채우기
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		d[i] = s[i]; 
	}

	for (int i = 1; i <= n; i++)
		d[i] = max(d[i], d[i - 1] + s[i]);

	cout << *max_element(d + 1, d + n + 1);
}