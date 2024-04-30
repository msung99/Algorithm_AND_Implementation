#include <bits/stdc++.h>
using namespace std;

vector<string> sounds, other_sounds, tmp;

vector<string> split(string& s, string sep) {
  vector<string> res;
  int pos = 0;

  while(pos < s.size()) {
    int next_pos = s.find(sep, pos);
    if(next_pos == -1) {
      next_pos = s.size();
    }
    if(next_pos - pos > 0) {
      res.push_back(s.substr(pos, next_pos - pos));
    }
    pos = next_pos + sep.size();
  }
  return res;
}


void solve() {
    string s;
    getline(cin, s);
    sounds = split(s, " ");

    while(true) {
        getline(cin, s);

        if(s == "what does the fox say?") {
            break;
        }

        tmp = split(s, " ");
        other_sounds.push_back(tmp[2]);
    }

    for(string sound : sounds) {
        bool is_other_sound = false;
        for(string other_sound : other_sounds) {
            if(other_sound != sound) {
                continue;
            }
            is_other_sound = true;
            break;
        }
        if(is_other_sound) {
            continue;
        }
        cout << sound << ' ';
    }
    cout << "\n";
    other_sounds.clear();
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    cin.ignore();

    while(t--) {
        solve();
    }

    return 0;
}
