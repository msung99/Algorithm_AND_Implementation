#include <bits/stdc++.h>
using namespace std;

string s;

// 0: error, 1: c++, 2: java
int getCode() {
    // error 인 경우
    if(s[0] == '_' || s[s.size() - 1] == '_') {
        return 0;
    }

    if(isupper(s[0])) {
        return 0;
    }

    bool is_under = false;
    bool is_upper = false;

    for(int i=1; i<s.size(); i++) {
        if(s[i] == '_') {
            if(s[i-1] == '_') {
                return 0;
            }
            is_under = true;
        }
        if(isupper(s[i])) {
            is_upper = true;
        }
    }
    // error 
    if(is_under && is_upper) {
        return 0;
    }
    // c++
    if(is_under) {
        return 1;
    }
    // java
    else {
        return 2;
    }
}

// c++ to java
void ctoj() {
    bool is_next_upper = false;
    for(char c : s) {
        if(c == '_') {
            is_next_upper = true;
            continue;
        }
        if(is_next_upper) {
            cout << (char) toupper(c);
        }
        else {
            cout << c;
        }
        is_next_upper = false;
    }
}

// java to c++
void jtoc() {
    for(char c : s) {
        if(isupper(c)) {
            cout << "_";
        }
        cout << (char) tolower(c);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    int code = getCode();

    if(code == 0) {
        cout << "Error!";
    } 
    // c++ 인 경우
    else if(code == 1) {
        ctoj(); // c++ to java
    }
    // java 인 경우
    else if(code == 2) {
        jtoc(); // java to c++
    }

    return 0;
}