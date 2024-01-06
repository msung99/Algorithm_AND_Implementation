#include <bits/stdc++.h>
using namespace std;

int cnt[200];
char mid;
int flag;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    for(int i=0; i<str.size(); i++) {
        cnt[str[i]]++;
    }

    string result;
    for(int i = 'Z'; i >= 'A'; i--) {
        if(cnt[i]) {
            if(cnt[i] % 2 == 1) {
                mid = char(i);
                flag++;
                cnt[i]--;
            }
            if(flag == 2) {
                break;
            }
            for(int j=0; j < cnt[i]; j+=2) {
                result = char(i) + result;
                result += char(i);
            }
        }
    }
    if(mid) {
        result.insert(result.begin() + result.size() / 2, mid);
    } 
    if(flag == 2) {
        cout << "I'm Sorry Hansoo\n"; 
    } else {
        cout << result << "\n";
    }
}