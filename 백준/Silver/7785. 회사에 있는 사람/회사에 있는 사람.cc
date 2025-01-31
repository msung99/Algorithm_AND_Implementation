#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    unordered_set<string> dic;    

    while(n--) {
        string s1, s2;
        cin >> s1 >> s2;

        if(s2 == "enter") {
            dic.insert(s1);
        } else {
            dic.erase(s1);
        }
    }

    vector<string> arr(dic.begin(), dic.end());
    sort(arr.begin(), arr.end(), greater<string>());

    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}