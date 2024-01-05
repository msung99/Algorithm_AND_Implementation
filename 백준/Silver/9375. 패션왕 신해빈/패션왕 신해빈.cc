#include <bits/stdc++.h>
using namespace std;

map<string, int> clothes;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        for(int i=0; i<n; i++) {
            string cloth, type;
            cin >> cloth >> type;
            clothes[type]++;
        }

        int result = 1;
        for(auto iterator : clothes) {
            result *= iterator.second + 1;
        }

        cout << result - 1<< "\n";
        clothes.clear();
    }
}