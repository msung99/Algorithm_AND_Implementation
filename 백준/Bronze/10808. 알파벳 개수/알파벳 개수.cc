#include <bits/stdc++.h>
using namespace std;

int arr[26];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    for(int i=0; i<str.size(); i++){ 
        int data = str[i] - 'a';
        arr[data]++;
    }

    for(int i=0; i<26; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}