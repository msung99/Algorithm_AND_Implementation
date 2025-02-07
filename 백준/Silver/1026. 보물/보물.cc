#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> arr1;
    vector<int> arr2;

    for(int i=0; i<n; i++) {
        int data;
        cin >> data;
        arr1.push_back(data);
    }

    for(int i=0; i<n; i++) {
        int data;
        cin >> data;
        arr2.push_back(data);
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end(), greater<int>());

    int res = 0;
    for(int i=0; i<n; i++) {
        res += (arr1[i] * arr2[i]);
    }
    cout << res;

    return 0;
}