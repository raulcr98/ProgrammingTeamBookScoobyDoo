#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 5e5 + 5;
long long acum[MAXN], costo, N, mn, mx, cnt;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> N >> costo) {
        memset(acum, 0, sizeof acum);
        while(N--) {
            cin >> cnt >> mn >> mx;
            if(mx > costo) {
                acum[mn] += cnt;
                acum[mx + 1] -= cnt;
            }
        }
        for(long long i = 1; i < MAXN; i++)
            acum[i] += acum[i - 1];
        cnt = 0;
        for(long long i = costo; i < MAXN; i++) {
            if(acum[i] * (i - costo) >= cnt) {
                cnt = acum[i] * (i - costo);
                mx = i;
            }
        }
        cout << mx << "\n";
    }
}
