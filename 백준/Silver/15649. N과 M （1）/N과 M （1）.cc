#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isused[10];
// 재귀적 사고: K-1 번쨰 수를 택했다면 K 번째 수도 택할 수 있다.
// K 번째수는 K-1 번째까지 등장하지 않았던 수 중에서 택할 수 있다.

// 현재 k번째 수를 택함을 의미
void func(int k) {
    if(k == m) {
        for(int i=0; i<m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=1; i<=n; i++) {
        if(!isused[i]) {
            arr[k] = i; // k번쨰 수는 k-1번째까지 등장하지 않았던 수 (1~n 사이의 수) 를 택한다.
            isused[i] = true;
            func(k+1); // k번쨰 수를 택했다면, k+1번쨰 수도 택할 수 있다.
            isused[i] = false;
        }        
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