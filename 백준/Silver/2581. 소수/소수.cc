/*
소수인지 판별하는 방법 : 소수일때는 소수의 합을 저장하는 sum 에 해당 변수를 더해준다

또, 소수를 구할때 M부터 작은 순서대로 소수 여부를 검사하기 떄문에 
min 값이 저장된 값이 없음을 나타내는 초기값 -1 인 경우에 처음으로 등장한 소수가 최소인 소수이다. 

이 최소인 소수를 min 에 저장하면 된다.

만약 주어진 M ~ N 범위에서 소수가 나타나지 않을경우 min 값이 초기값 그대로 -1 일 것이기 떄문에,
최종 결과를 출력하기 전에 min 값을 -1 인지 체크하고 결과를 출력한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m, n;
	int sum = 0;
	int min = -1; // 소수의 최솟값
	int cnt = 0;

	cin >> m >> n;

	for (int i = m; i <= n; i++) {
		for (int div = 1; div <= i; div++) {  // 1 ~ i 사이의 숫자로 모두 나누기를 진행. 1과 i 로 나누었을떄를 제외하고, 나머지가 0이 나오는게 있다면 소수가 아니다. 
			if (i % div == 0)  // 소수가 맞다면 i % div 의 값이 0이 되는 경우가 딱 2번만 나올것이다(div 값이 1 일때랑 i 일때 두가지경우) => 이에 따라 cnt 값이 2가 된다.
				cnt++; 
		}
		if (cnt == 2) {  // i가 소수일때
			if (min == -1)  // 지정된 소수의 최솟값이 없을 때
				min = i;
			sum += i;
		}
		cnt = 0; // 다음 숫자(i) 에 대해서 소수인지 판별하기 전에 cnt 를 0으로 초기화시켜버림
	}

	if (min == -1)
		cout << -1 << '\n';
	else
		cout << sum << '\n' << min << '\n';
}