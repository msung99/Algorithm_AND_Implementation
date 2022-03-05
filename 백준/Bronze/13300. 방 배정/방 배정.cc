#include<iostream>
using namespace std;
int stu[2][6];
int main()
{
    int n, k, s, y, cnt = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> y;
        stu[s][y - 1]++;
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            //나눈 몫= 방의개수
            cnt += stu[i][j] / k;
            //나머지있을시 방의개수+1
            if (stu[i][j] % k != 0)
                cnt++;
        }
    }
    cout << cnt << endl;
}
