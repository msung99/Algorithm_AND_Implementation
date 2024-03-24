#include <bits/stdc++.h>
using namespace std;

bool palindrome[2002][2002]; // palindrome[i][j] : 원소 i~j번째 부분 문자열이 팰린드롬인지 참/거짓 저장
int n;
int arr[2002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    // 초기값 설정1
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        palindrome[i][i] = true; // 길이가 1짜리 문자열은 무조건 팰린드롬이다;
    }

    // 초기값 설정2
    for(int i=1; i<=n-1; i++) {
        if(arr[i] == arr[i+1]) {
            palindrome[i][i+1] = true;
        }
    }

    // 반복문을 거꾸로 돌려서 palinedrome[i+1][j-1] 에 접근
    for(int i=n-1; i>=1; i--) {
        for(int j=i+2; j<=n; j++) {
            if((arr[i] == arr[j]) && (palindrome[i+1][j-1])) {
                palindrome[i][j] = true;
            }
        }
    }

    int t;
    cin >> t;
    while(t--) {
        int u, v;
        cin >> u >> v;
        if(palindrome[u][v]) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }

    return 0;
}