#include <bits/stdc++.h>
using namespace std;

int n;
int arr[10];
int num[10];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<n; i++) {
        cin >> num[i];
    }

    int k;
    cin >> k;

    while(k--) {
        int idx = n-1;
        bool isOverflow = true;

        while(isOverflow) {
            if(num[idx] == arr[idx]) {
                isOverflow = true;
                num[idx] = 0;
            } else {
                isOverflow = false;
                num[idx]++;
            }
            idx--;
        }
    }

    for(int i=0; i<n; i++) {
        cout << num[i];
    }

    return 0;
}