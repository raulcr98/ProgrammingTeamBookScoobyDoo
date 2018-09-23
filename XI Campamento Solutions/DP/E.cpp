#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1600, MAXM = 2100;
int dp[MAXN][MAXM], N, cont;
string word;

pair<int, int> hijos[MAXN];
string cadena [MAXN], g;
map<string, int> mapa;

int caminar(string buscar, int pos) {
    int len = buscar.length(), t = 0;

    while(t < len && pos < N) {
        if(g[pos] == buscar[t]) pos++;

        t++;
    }

    return pos;
}

int f(int node, int pos) {
    if(node == -1) return pos;

    if(dp[node][pos] != -1) return dp[node][pos];

    if(hijos[node].first == -1) return dp[node][pos] = caminar(cadena[node], pos);

    int sol = f(hijos[node].first, pos);

    if(hijos[node].second != -1 ) sol = f(hijos[node].second, sol);

    return dp[node][pos] = sol;
}


int format(string cad) {
    if(mapa.find(cad) == mapa.end()) mapa[cad] = cont++;

    return mapa[cad];
}

void lectura() {
    string cad, left = "", rigth1 = "", rigth2 = "";
    int node, hijo1 = -1, hijo2 = -1;
    cin >> left >> cad >> rigth1;

    if(rigth1[0] >= 'A' && rigth1[0] <= 'Z') cin >> cad >> rigth2;

    node = format(left);
    hijo1 = format(rigth1);
    hijo2 = format(rigth2);
    hijos[node].first = hijo1;
    hijos[node].second = hijo2;

    if(hijo2 == -1) cadena[hijo1] = rigth1;
}


int main() {
   // ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, k;
    cin >> t;

    while(t--) {
        cont = 1;
        mapa.clear();
        mapa[""] = -1;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < MAXN; i++) hijos[i].first = hijos[i].second = -1;
        cin >> k;
        for(int i = 0; i < k; i++) lectura();

        string ini;
        cin >> ini >> g;
        N = g.length();

        if(mapa.find(ini) == mapa.end()) {
            if(N == caminar(ini, 0))cout << "YES\n";
            else cout << "NO\n";
        } else {
            if(N == f(mapa[ini], 0)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}

