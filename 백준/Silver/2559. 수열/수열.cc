#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int sum[100001]; // sum[3] = sum[2] + arr[3];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i=1; i <= n; i++) {
        int data;
        cin >> data;
        sum[i] = sum[i-1] + data; // sum[i] : 0 ~ i번쨰 데이터들의 합
    }

    int result = sum[k];
    for(int i = k+1; i <= n; i++) {
        if(result < sum[i] - sum[i-k]) {
            result = sum[i] - sum[i-k];
        }
    }
    cout << result;
    return 0;
}