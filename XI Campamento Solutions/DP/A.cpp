#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 21;

ll N, dp[MAXN][1 << 20];
bool ady[MAXN][MAXN];


ll f(int msk, int ei) {
    if(!msk)return 1;

    if(ei >= N)return 0;

    if(dp[ei][msk] != -1) return dp[ei][msk];

    ll sol = 0;

    for(int i = 0; i < N; i++)
        if((msk & (1 << i)) && ady[ei][i]) sol += f(msk ^ (1 << i), ei + 1);

    dp[ei][msk] = sol;
    return sol;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t, x;
    cin >> t;

    while(t--) {
        memset(ady, 0, sizeof(ady));
        memset(dp, -1, sizeof(dp));

        cin >> N;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> x;

                if(x) ady[i][j] = true;
            }
        }

//        for(int i = 0; i < N; i++) {
//
//            for(int j = 0; j < N; j++)
//                cout << ady[i][j];
//
//            cout << '\n';
//        }

        cout << f((1 << N) - 1, 0) << '\n';

    }


    return 0;
}

//asdasd
