#include <bits/stdc++.h>
using namespace std;

int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if(n % 2 == 1) {
        cout << "SK";
    } else {
        cout << "CY";
    }

    return 0;
}