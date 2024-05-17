#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++) {
        int data;
        cin >> data;
        arr.push_back(data);
    }

    sort(arr.begin(), arr.end());

    int m;
    cin >> m;
    while(m--) {
        int target;
        cin >> target;
        cout << binary_search(arr.begin(), arr.end(), target) << " ";
    }

    return 0;
}