#include <bits/stdc++.h>
using namespace std;

// 재귀적 사고: K-1 번쨰 수를 택했다면 K 번째 수도 택할 수 있다.
// K 번째수는 K-1 번째까지 등장하지 수 중에서도 택할 수 있다.
int arr[10];
int n, m;

void func(int k) {
    if(k == m) {
        for(int i=0; i<m; i++) {
            cout << arr[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for(int i=1; i<=n; i++) {
        arr[k] = i;
        func(k+1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    func(0);

    return 0;
}