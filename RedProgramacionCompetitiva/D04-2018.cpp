/* DP */
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400;

int N, a[MAXN], now, bef = (1 << 31);

int main()
{
    cin >> N;
    for(int i = 1 ; i <= N ; i++){
        cin >> a[i];
    }

    int sol = 100;
    for(int i = 1 ; i <= N ; i++){
        if(a[i] > bef){
            sol += min(sol / bef, (int)1e5) * (a[i] - bef);
        }
        bef = a[i];
    }


    cout << sol;
    return 0;
}
