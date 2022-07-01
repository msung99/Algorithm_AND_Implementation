#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MIN = 2000000;
const int HALF = MIN / 2;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> numcnt(MIN + 2);
	int n, data;
	cin >> n;
	while (n--) {
		cin >> data;
		numcnt[data + HALF]++;  // 절댓값임을 고려하여, 음수가 나올수 있음을 감안하고 코드를 구성.
	}

	for (int i = 0; i <= MIN; i++) {
		while (numcnt[i]--)
			cout << i - HALF << '\n';
	}
}