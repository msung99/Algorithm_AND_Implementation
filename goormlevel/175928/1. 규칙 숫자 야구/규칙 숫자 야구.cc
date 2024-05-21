#include <bits/stdc++.h>
using namespace std;

int tryCount;
string ans, input;
int strikeCount;
int ballCount;
int failCount;
int status[5]; // status[i] : 0 -> 스트라이크, 1 -> 볼,  2 -> 패일

void play() {
    bool isBallOccured = false;

    for(int i=0; i<ans.size(); i++) {
        if(input[i] == ans[i]) {
            status[i] = 0; // strike
        } else {
            if(ans.find(input[i]) != string::npos) {
                status[i] = 1; // ball
            } else  {
                status[i] = 2; // fail
            }
        }

        if(status[i] == 0) { // strike
            continue;
        } else if(status[i] == 1) { // ball
            isBallOccured = true;
        } else if(status[i] == 2) { // fail
            do {
                int tmp = input[i] - '0';
                tmp = (tmp + 1) % 10;
                input[i] = tmp + '0';
            } while(count(input.begin(), input.end(), input[i]) > 1);
        }
     }
     
     if(isBallOccured) {
        vector<int> exclude_indices;
        for(int i = 0; i < ans.size(); i++) {
            if(status[i] == 0) {
                exclude_indices.push_back(i);
            }
        }

        string temp = input;
        int n = temp.size();

        // Rotate the characters not in exclude_indices to the right
        for(int i = n - 1; i >= 0; --i) {
            if(find(exclude_indices.begin(), exclude_indices.end(), i) == exclude_indices.end()) {
                int next_pos = (i + 1) % n;
                while(find(exclude_indices.begin(), exclude_indices.end(), next_pos) != exclude_indices.end()) {
                    next_pos = (next_pos + 1) % n;
                }
                temp[next_pos] = input[i];
            }
        }
        input = temp;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> ans >> input;

    bool regame = true;

    int tmp  = 0;
    while(regame) {
        if(tmp > 10) {
            break;
        }
        tmp++;
        tryCount++;
        play();

        regame = false;

        for(int i=0; i<4; i++) {
            if(status[i] != 0) {
                regame = true;
            }
        }
    }
    cout << tryCount;

    return 0;
}