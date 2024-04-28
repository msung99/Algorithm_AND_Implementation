#include <bits/stdc++.h>
using namespace std;

vector<string> alphas = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    
    for(auto alpha : alphas) {
        while(true) {
            int pos = s.find(alpha);
            if(pos == string::npos) {
                break;
            }
            s.replace(pos, alpha.size(), "1");
        }
    }

    cout << s.size();

    return 0;
}