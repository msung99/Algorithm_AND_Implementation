#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int res[10];

void func(int k) {
    if(k == m) {
        for(int i=0; i<m; i++) {
            cout << res[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for(int i=0; i<n; i++) {
        res[k] = arr[i];
        func(k+1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    func(0);

    return 0;
}