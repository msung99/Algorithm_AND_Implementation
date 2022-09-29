#include <iostream>
#include <string>

using namespace std;

bool dp[2501][2501];

int main() {
    
    int count[2501];
    
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    
    for (int i=1; i<=n; i++) {
        dp[i][i] = true;
    }
    for (int i=1; i<=n-1; i++) {
        if (s[i] == s[i+1]) {
            dp[i][i+1] = true;
        }
    }
    for (int k=2; k<n; k++) {
        for (int i=1; i<=n-k; i++) {
            int j = i+k;
            if (s[i] == s[j] && dp[i+1][j-1]){
                dp[i][j] = 1;
            }
        }
    }
    count[0] = 0;
    for (int i=1; i<=n; i++) {
        count[i] = 987654321;
        for (int j=1; j<=i; j++) {
            if (dp[j][i]) {
                if (count[i] > count[j-1]+1) {
                    count[i] = count[j-1]+1;
                }
            }
        }
    }

    cout << count[n] << '\n';
    return 0;
}