#include <bits/stdc++.h>
using namespace std;

int n;
int lc[30];
int rc[30];

void preOrder(int cur) {
    cout << char(cur + 'A' - 1);
    if(lc[cur] != 0) {
        preOrder(lc[cur]);
    }
    if(rc[cur] != 0) {
        preOrder(rc[cur]);
    }
}

void inOrder(int cur) {
    if(lc[cur] != 0) {
        inOrder(lc[cur]);
    }
    cout << char(cur + 'A' - 1);
    if(rc[cur] != 0) {
        inOrder(rc[cur]);
    }
}

void postOrder(int cur) {
    if(lc[cur] != 0) {
        postOrder(lc[cur]);
    }
    if(rc[cur] != 0) {
        postOrder(rc[cur]);
    }
    cout << char(cur + 'A' - 1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) {
        char c, l, r;
        cin >> c >> l >> r;
        if(l != '.') {
            lc[c-'A'+1] = l-'A'+1;
        }
        if(r != '.') {
            rc[c-'A'+1] = r-'A'+1;
        }
    }

    preOrder(1);
    cout << "\n";

    inOrder(1);
    cout << "\n";

    postOrder(1);
    cout << "\n";

    return 0;
}