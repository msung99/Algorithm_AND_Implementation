#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> flower;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        int month1, day1, month2, day2;
        cin >> month1 >> day1 >> month2 >> day2;
        int date1 = month1 * 100 + day1; // ex) 5월 31일은 531로 게산된다.
        int date2 = month2 * 100 + day2;
        flower.push_back({date1, date2});
    }

    int date = 301; // 시작 날짜는 3월 1일로 설정
    int ans = 0;

    // 날짜가 11월 30일이 될때까지 반복한다.
    while(date <= 1130) {
        int next_date = date;

        // for 문을 돌면서 현재 날짜(date) 에서 도달할 수 있는 가장 늦은 날짜를 추출
        for(int i=0; i<n; i++) {
            if(flower[i].first <= date && flower[i].second > next_date) {
                next_date = flower[i].second;
            }
        }

        // 현재 날짜(date) 에서 더 이상 진전이 불가능한 경우
        if(date == next_date) {
            cout << 0;
            return 0;
        }

        date = next_date;
        ans++;
    }

    cout << ans;

    return 0;
}