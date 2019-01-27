#include <bits/stdc++.h>

using namespace std;

long long sumat(long long N){
    return N * (N - 1) / 2;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long N, S, m, mit;
    cin >> N;
    S = sumat(N);
    m = (S + 1) / 2;

    long long ini = 1, fin = N;
    while(ini < fin){
        mit = (ini + fin + 1) / 2;

        if(S - sumat(N - mit + 1) < m)
            ini = mit;
        else
            fin = mit - 1;
    }

    cout << ini << '\n';
}
