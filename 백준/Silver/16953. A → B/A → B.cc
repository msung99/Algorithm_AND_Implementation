#include <bits/stdc++.h>
using namespace std;

int mini = 9999999;
long long A, B;
int cnt;

void DFS(long long a, int cnt) {
	if (a > B)
		return;

	if (a == B) // A를 B로 만든경우
		mini = min(mini, cnt);

	DFS(a * 2, cnt + 1); // A를 B로 만들기위해 A에 2를 곱하기
	DFS(a * 10 + 1, cnt + 1); // A를 B로 만들기위해 일의자리에 1을 추가하기
}

int main(void)
{
	cin >> A >> B;
	DFS(A, 1);

	if (mini == 9999999) // A를 B로 만들 수 없는 경우에는 -1을 출력
		cout << -1;
	else
		cout << mini;
}