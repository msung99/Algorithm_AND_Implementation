#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[100002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for(int i=0; i<n; i++) {
        cin >> arr[i];        
    }

    int en = 0;
    int prefix_sum = arr[0];
    int min_len = 2100000000;
    
    for(int st=0; st<n; st++) {
        while(en < n && prefix_sum < s) {
            en++;
            if(en != n) {
                prefix_sum += arr[en];
            }
        }
        if(en == n) {
                break;
        }
        min_len = min(min_len, en - st + 1);
        prefix_sum -= arr[st];
    }
    
    if(min_len == 2100000000) {
        min_len = 0;
    }

    cout << min_len;
    return 0;
}