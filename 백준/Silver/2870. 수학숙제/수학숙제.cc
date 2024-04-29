#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> numbers;

void extractNumbers() {
    cin >> s;
    int next_pos = 0;
    int pos = 0;

    while(true) {
        while(s[next_pos] >= 'a' && s[next_pos] <= 'z') {
            next_pos++;
        }

        pos = next_pos;
        if(pos >= s.length()) {
            break;
        }

        while(s[next_pos] >= '0' && s[next_pos] <= '9') {
            next_pos++;
        }
        string number = s.substr(pos, next_pos - pos);
        numbers.push_back(number);
        pos = next_pos;
    }
}

void removeZeros() {
    for(string& s : numbers) {
        int pos = 0;
        while(s[pos] == '0') {
            pos++;
        }
        string ss = s.substr(pos, s.length() - pos);
        if(ss == "") {
            ss = "0";
        }
        s = ss;
    }
}

bool cmp(string& a, string& b) {
    if(a.length() == b.length()) {
        return a < b;
    }
    return a.length() < b.length();
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        extractNumbers();
    }
    removeZeros();

    sort(numbers.begin(), numbers.end(), cmp);
    for(string s : numbers) {
        cout << s << "\n";
    }

    return 0;
}