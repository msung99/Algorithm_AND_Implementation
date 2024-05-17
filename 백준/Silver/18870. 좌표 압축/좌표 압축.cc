// 중복을 제외하고 나보다 작은 원소가 몇개있는지를 묻는 문제
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000005];
vector<int> origin; // 중복을 제거하지 않은 원본 배열 
vector<int> uni; // 중복을 제거한 새로운 배열

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
        origin.push_back(arr[i]);
    }    

    sort(origin.begin(), origin.end()); // 정렬

    // 중복을 제거한 원소들로 새롭게 구성     
    for(int i=0; i<n; i++) {
        if(origin[i] == 0 || origin[i-1] != origin[i]) {
            uni.push_back(origin[i]);
        }
    }

    // arr[i] 보다 작은 원소가 몇개 존재하는지 카운팅
    for(int i=0; i<n; i++) {
        cout << lower_bound(uni.begin(), uni.end(), arr[i]) - uni.begin() << ' ';
    }

    return 0;
}