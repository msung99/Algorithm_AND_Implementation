#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, cnt;
int coin[10];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for(int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	for (int i = n - 1; i >= 0;) {
		if (coin[i] > k) {
			i--;
			continue;
		}
		k = k - coin[i];
		cnt++;
	}
	cout << cnt;
}