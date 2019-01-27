#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int N, s[MAXN], w, T;

bool ranking(int k){
    for(int i = N - 2 * k - 1, j = 2 ; i > j; i--, j++)
        if(s[i] + s[j] >= w) return 0;
    return 1;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 1 ; i <= N ; i++){
            cin >> s[i];
        }

        w = s[1] + s[N];
        int ini = 1, fin = N / 2;

        while(ini < fin){
            int mit = (ini + fin) / 2;

            if(ranking(mit - 1))
                fin = mit;
            else
                ini = mit + 1;
        }

        cout << ini << '\n';
    }
}
