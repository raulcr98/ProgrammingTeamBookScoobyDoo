/*
    2 Tablas acumulativas
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 1;

int tades[MAXN], tador[MAXN], a[MAXN];
bool b[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    for(int i = 1 ; i <= N ; i++){
        cin >> a[i];
    }

    for(int i = 1 ; i <= N ; i++){
        cin >> b[i];
        if(b[i])
            tades[i] = a[i];
        else
            tador[i] = a[i];
    }

    for(int i = 1 ; i <= N ; i++){
        tades[i] += tades[i - 1];
        tador[i] += tador[i - 1];
    }
    int maxd = 0;
    for(int i = M ; i <= N ; i++){
        if(maxd < tador[i] - tador[i - M])
            maxd = tador[i] - tador[i - M];
    }

    cout << maxd + tades[N];
    return 0;
}
