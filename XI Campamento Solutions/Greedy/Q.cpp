#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 5;
int acum[maxn], lista[maxn], k1[maxn], k2[maxn], maximo[maxn];
int n, k;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> lista[i];

    for(int i = 1; i <= n; i++) acum[i] = (acum[i - 1] + lista[i]);

    for(int i = 1; i <= n - k; i++) k1[i] = acum[i + k - 1] - acum[i - 1];

    for(int i = n - k + 1; i <= n; i++) k1[i] = acum[n] - acum[i - 1];

    for(int i = 1; i <= n - 2 * k; i++) k2[i] = acum[i + k + k - 1] - acum[i - 1];

    for(int i = n - 2 * k + 1; i <= n; i++) k2[i] = acum[n] - acum[i - 1];

    int maximoVal = 0;

    for(int i = 1; i <= n; i++) maximoVal = max(maximoVal, k2[i]);

    for(int i = 1; i <= n; i++) maximo[i] = max(maximo[i - 1], k1[i]);

    for(int i = k; i <= n; i++) maximoVal = max(maximoVal, maximo[i - k] + k1[i]);

    cout << maximoVal << '\n';

    return 0;
}
/*ok*/
