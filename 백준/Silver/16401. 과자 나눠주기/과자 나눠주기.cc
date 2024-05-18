#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, n;
    cin >> m >> n;

    vector<int> l;

    for(int i=0; i<n; i++) {
        int len;
        cin >> len;
        l.push_back(len);
    }

    int left = 1;
    int right = *max_element(l.begin(), l.end());
    int snack = 0;

    // 길이가 mid 인 과자를 나눠줄 떄 몇명(count) 에게 나눠줄 수 있는지를 구함
    while(left <= right) {
        int mid = (left + right) / 2;
        int count = 0;
        for(int i=0; i<n; i++) {
            count += l[i] / mid; // 각 과자에 대해 카운팅
        }

        if(count >= m) { // m명 이상에게 길이가 Mid 인 과자를 나눠줄 수 있다면
            left = mid + 1;
            snack = mid;
        }
        else if(count < m) {
            right = mid - 1;
        }
    }
    cout << left - 1;

    return 0;
}