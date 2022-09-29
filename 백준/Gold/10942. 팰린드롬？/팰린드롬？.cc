/*
palindrom[s][e] = s ~ e 까지 수의 팰린드롬 여부

s ~ e 까지가 팰린드롬이려면 s+1 ~ e-1 까지도 팰린드롬이여야 한다.
이 조건은 arr[s] == arr[e] && palindrom[s+1][e-1] == true 로 표현할 수 있다.
*/

#include <bits/stdc++.h>
using namespace std;

int arr[2001];
bool palindrom[2001][2001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
		palindrom[i][i] = true; // i~i번째 수는 팰린드롬이다.0

	for (int i = 1; i <= n - 1; i++) {
		if (arr[i] == arr[i + 1]) // i ~ (i+1) 번째 수에 대해서도 초기값 처리를 해줘야한다.
			palindrom[i][i + 1] = true;
	}

	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 2; j <= n; j++) {
			// palindrom[s][e] = s ~ e 까지 수의 팰린드롬 여부
			if (arr[i] == arr[j] && palindrom[i + 1][j - 1] == true) // s ~ e 까지가 팰린드롬이려면 s+1 ~ e-1 까지도 팰린드롬이여야 한다.
				palindrom[i][j] = true; // 이 조건은 arr[s] == arr[e] && palindrom[s+1][e-1] == true 로 표현할 수 있다.
		}
	}

	int m, s, e;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << palindrom[s][e] << '\n';
	}
}