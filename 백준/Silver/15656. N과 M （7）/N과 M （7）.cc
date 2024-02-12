#include <bits/stdc++.h>
using namespace std;

int n, m;
int num[10];
int arr[10];
bool isused[10];

void func(int k) { // 현재 k개까지 수를 택했음.
    if (k == m) { // m개를 모두 택했으면
        for (int i = 0; i < m; i++)
            cout << num[arr[i]] << ' '; // arr에 기록해둔 인덱스에 대응되는 수를 출력
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
            arr[k] = i; // k번째 인덱스를 i로 정함
            func(k + 1); // 다음 인덱스를 정하러 한 단계 더 들어감        }
    }
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);

	func(0);

}