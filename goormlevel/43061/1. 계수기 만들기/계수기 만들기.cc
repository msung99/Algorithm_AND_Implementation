#include <bits/stdc++.h>
using namespace std;

int n, k;
int counter[10];
int number[10];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> counter[i];
    }

    for(int i=0; i<n; i++) {
        cin >> number[i];
    }

    cin >> k;
    
    while(k--) {
        int idx = n-1;
        bool overflow = true;

        while(overflow) {
            number[idx] += 1;
            if(number[idx] > counter[idx]) {
                number[idx] = 0;
                idx--;
                overflow = true;

                if(idx < 0) {
                    break;
                }

            } else {
                overflow = false;
            }
        }
    }

    for(int i=0; i<n; i++) {
        cout << number[i];
    }

    return 0;
}