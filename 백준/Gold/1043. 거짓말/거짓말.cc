#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> party;

bool isMatch(vector<int> group, int person) {
    auto it = find(group.begin(), group.end(), person);
    if(it != group.end()) {
        return true;
    }
    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    queue<int> q;

    int t;
    cin >> t;
    while(t--) {
        int data;
        cin >> data;
        q.push(data);
    }

    while(m--) {
        int t;
        cin >> t;
        vector<int> tmp;
        while(t--) {
            int data;
            cin >> data;
            tmp.push_back(data);            
        }
        party.push_back(tmp);
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i=0; i<party.size(); i++) {
            if(isMatch(party[i], cur)) {
                for(auto person : party[i]) {
                    q.push(person);
                }
                party.erase(party.begin() + i);
            }
        }
    }
    cout << party.size();

    return 0;
}