#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MAXN = 105;
ll oo=1e9;
ll N;
ll acum[MAXN], dp[MAXN][MAXN];


ll f(ll a, ll b) {
    if(a >= b )return 0;

    if(dp[a][b] != -1) return dp[a][b];

    ll sol = oo;

    for(ll i = a; i < b; i++)
        sol = min(sol, f(a, i) + f(i + 1, b) + (((acum[i] - acum[a - 1]) % 100) * ((acum[b] - acum[i]) % 100)));

    dp[a][b] = sol;

    return sol;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll x;

    while(cin >> N) {
        memset(dp, -1, sizeof(dp));
        memset(acum, 0, sizeof(acum));

        for(ll i = 1; i <= N; i++) {
            cin >> acum[i];
            acum[i] += acum[i - 1];
        }

        int tt = N;
        cout << f(1, tt) << '\n';
    }

    return 0;
}

//asdasd
