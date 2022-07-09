#include <iostream>
using namespace std;

// 소수란 1과 자기 자신으로만 나누어떨어지는 1보다 큰 정수를 의미
int main() {
	int N, result = 0;
	int temp, cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		for (int div = 1; div <= temp; div++) {
			if (temp % div == 0)
				cnt++;
		}
		if (cnt == 2)	// 1과 자신으로만 나누어 떨어진 경우 == 소수인 경우
			result++;
		cnt = 0;
	}
	cout << result << '\n';
}