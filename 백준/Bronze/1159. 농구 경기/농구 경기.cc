#include <bits/stdc++.h>
using namespace std;

int arr[26];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        string str;
        cin >> str;        
        arr[str[0] - 'a']++;
    }

    string res = "";
    for(int i=0; i<26; i++) {
        if(arr[i] >= 5) {
            res += (i + 'a');
        }
    }
    if(res.size() != 0){
        cout << res; 
    } else {
        cout << "PREDAJA";
    }
}