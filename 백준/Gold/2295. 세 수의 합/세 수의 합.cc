// 이 문제처럼 뭔가 2개를 묶고나서 어느 한쪽의 값을 이분탐색으로 찾아서 시간복잡도를 낮추는 아이디어는 이분탐색 응용 문제에서 많이 등장함

#include <bits/stdc++.h>
using namespace std;

// a[i] + a[j] + a[k] = a[l] 을 만족하는 a[l] 중에서 최댓값
// two[m] + a[k] = a[l] 을 만족하는 a[l] 중에서 최댓값

int n;
int arr[1005];
vector<int> two;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            two.push_back(arr[i] + arr[j]);
        }
    }

    sort(two.begin(), two.end());

    // arr[i] - arr[j] 값이 two 배열에 존재하는지 확인
    for(int i=n-1; i>0; i--) {
        for(int j=0; j<i; j++) {
            if(binary_search(two.begin(), two.end(), arr[i] - arr[j])) {
                cout << arr[i];
                return 0;
            }
        }
    }

    return 0;
}