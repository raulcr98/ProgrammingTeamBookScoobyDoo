/*
    Fuerza Bruta
    By tasK!ll
*/

#include <bits/stdc++.h>


using namespace std;

const int MAXN = 1e5 + 1;

int N, M, K, aux = 1;
long long c[MAXN], sol;
map<string, int> id1;
//map<int, string> id2;
int ad[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N>>K>>M;
    for(int i = 1 ; i <= N ; i++){
        string k;
        cin >> k;
        id1[k] = aux;
        aux++;
    }

    for(int i = 1 ; i <= N ; i++){
        cin >> c[i];
    }

    int ccom = 0;
    for(int i = 1;  i <= K ; i++){
        int ci;
        long long mn = 1e9;
        cin >> ci;
        for(int j = 1 ; j <= ci ; j++){
            cin >> ad[j];
            if(mn > c[ad[j]])
                mn = c[ad[j]];
        }
        for(int j = 1 ; j <= ci ; j++){
            c[ad[j]] = mn;
        }
    }

    for(int i = 1 ; i <= M ; i++){
        string a;
        cin >> a;
        sol += c[id1[a]];
    }

    cout << sol;
}