#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 1;
const int MAXM = 18;

int N, M, root;
int lca[MAXN][MAXM];
int level[MAXN], masl[MAXN / 2];
vector<int> ad[MAXN];
vector<int> p[MAXN / 2];

void build_lca(){
    queue<int> Q;
    Q.push(root);
    level[root] = 1;

    while(!Q.empty()){
        int nod = Q.front();
        Q.pop();

        for(int i = 0 ; i < ad[nod].size() ; i++){
            int nn = ad[nod][i];

            if(level[nn])
                continue;

            level[nn] = level[nod] + 1;
            lca[nn][0] = nod;
            Q.push(nn);

            int lg = log2(level[nn]);

            for(int k = 1 ; k <= lg ; k++)
                if(lca[nn][k - 1])
                    lca[nn][k] = lca[lca[nn][k - 1]][k - 1];
        }
    }
}

int query_lca(int a, int b){
    if(level[a] > level[b])
        swap(a, b);

    int lg = log2(level[b]);
    for(int i = lg ; i >= 0 ; i--)
        if(lca[b][i] && level[b] - (1 << i) >= level[a])
            b = lca[b][i];

    if(a == b)
        return a;

    lg = log2(level[a]);
    for(int i = lg ; i >= 0 ; i--)
        if(lca[a][i] && lca[a][i] != lca[b][i])
            a = lca[a][i] , b = lca[b][i];

    return lca[a][0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("cowpol.in", "r", stdin);
    //freopen("cowpol.out", "w", stdout);

    cin >> N >> M;

    for(int i = 1 ; i <= N ; i++){
        int a, b; cin >> a >> b;
        if(!b)
            root = i;
        else
            ad[b].push_back(i);
        p[a].push_back(i);
    }

    build_lca();

    for(int i = 1 ; i <= M ; i++)
        for(int j = 0 ; j < p[i].size() ; j++)
            if(level[p[i][j]] > level[masl[i]])
                masl[i] = p[i][j];

    for(int i = 1 ; i <= M ; i++){
        int sol = 0;

        for(int j = 0 ; j < p[i].size() ; j++){
            int a = level[masl[i]];
            int b = level[p[i][j]];
            int c = 2 * level[query_lca(masl[i], p[i][j])];

            if(sol < a + b - c)
                sol = a + b - c;
        }

        cout << sol << '\n';
    }

    return 0;
}