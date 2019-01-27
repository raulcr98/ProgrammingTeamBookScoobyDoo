#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int n, sol, ini, fin, a[MAX], dp[MAX], ult[MAX];
string s;

void solve() {
    memset(dp, 0, sizeof dp);
    memset(ult, 0, sizeof ult);
    for(int i = 1; i <= n; i++) {
        if(a[i] == -1) {
            if(dp[i - 1] >= 1 && i != 1)
                ult[i] = ult[i - 1];
            else
                ult[i] = i;
            dp[i] = max(dp[i - 1] - 1, -1);
        } else {
            if(dp[i - 1] >= 0 && i != 1)
                ult[i] = ult[i - 1];
            else
                ult[i] = i;
            dp[i] = max(dp[i - 1] + 1, 1);
        }
        if(dp[i] > sol)
            sol = dp[i], fin = i, ini = ult[i];
        else if(dp[i] == sol) {
            if(ult[i] < ini)
                ini = ult[i], fin = i;
            else if(ult[i] == ini)
                fin = min(fin, i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.size();

    for(int i = 1; i <= n; i++)
        if(s[i - 1] == 'B')
            a[i] = -1;
        else
            a[i] = 1;

    solve();

    for(int i = 1; i <= n; i++)
        a[i] *= -1;

    solve();

    cout << ini << ' ' << fin << '\n';
}
