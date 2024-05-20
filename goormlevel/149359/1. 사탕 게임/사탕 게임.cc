#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int res = 0;
    int score1 = 0;
    int score2 = 0;

    cin >> n;
    for(int i=0; i<n; i++) {
        int data;
        cin >> data;

        res = data / 3;
        res += data % 3;

        if(res % 2 == 0) {
            score1++;
        } else {
            score2++;
        }
    }

    if(score1 > score2) {
        cout << score1;
    } else if(score1 < score2) {
        cout << score2;
    } else {
        cout << "tie";
    }

    return 0;
}