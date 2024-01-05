#include <bits/stdc++.h>
using namespace std;

map<string, int> names;
map<int, string> numbers;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        string str;
        cin >> str;
        names.insert({str, i});
        numbers.insert({i, str});
    }


    for(int i=1; i<=m; i++) {
        string str;
        cin >> str;

        if(isalpha(str[0])) {
            cout << names[str] << "\n";
        } else {
            cout << numbers[stoi(str)] << "\n";
        }
    }
    return 0;
}