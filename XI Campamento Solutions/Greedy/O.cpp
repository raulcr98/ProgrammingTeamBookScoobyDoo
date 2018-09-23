#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 101;

int N, M, cont, ord[MAXN];
bool ok[MAXN];
vector<int> ad[MAXN];
vector<pii> sol;

bool dfs(int nodo){
    if(ok[nodo]) return 1;

    int c = 0;

    for(int i = 0 ; i < ad[nodo].size() ; i++){
        int nn = ad[nodo][i];
        if(!ok[nn]){
            bool oka = dfs(nn);
            if(oka)
                c++;
        }
        else if(ok[nn]) c++;
    }

    if(c == ad[nodo].size()){
        ord[nodo] = ++cont;
        ok[nodo] = true;
        return 1;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> N >> M && (N || M)){
        cont = 0;
        sol.clear();
        memset(ok, 0, sizeof(ok));
        memset(ord, 0, sizeof(ord));
        for(int i = 1 ; i <= N ; i++)
            ad[i].clear();
        for(int i =1 ; i <= M ; i++){
            int a, b; cin >> a >> b;
            ad[b].push_back(a);
        }

        for(int i = 1 ; i <= N ; i++){
            if(!ok[i]){
                dfs(i);
            }
        }

        for(int i = 1 ; i <= N ; i++)
            sol.push_back(pii(ord[i], i));
        sort(sol.begin(), sol.end());
        cout << sol[0].second;
        for(int i=1 ; i < sol.size() ; i++)
            cout << ' ' << sol[i].second;
        cout << '\n';
    }

    return 0;
}
/*ok*/
