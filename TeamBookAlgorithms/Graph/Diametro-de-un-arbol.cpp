#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ar;

const int MAXN = 4e4 + 1;

int N, M, mn, mx;
vector<ar> ad[MAXN];
bool mk[MAXN];

void dfs(int nod, int cst){
    if(mk[nod])
        return;

    if(cst > mx){
        mx = cst;
        mn = nod;
    }

    mk[nod] = true;

    for(int i = 0 ; i < ad[nod].size() ; i++){
        int nn = ad[nod][i].first;
        int nc = ad[nod][i].second + cst;

        dfs(nn, nc);
    }
}

int main()
{
    cin >> N >> M;

    for(int i = 1 ; i <= M ; i++){
        int a, b, c;
        char d;

        cin >> a >> b >> c >> d;

        ad[a].push_back(ar(b, c));
        ad[b].push_back(ar(a, c));
    }

    dfs(1, 0);

    fill(mk + 1, mk + 1 + N, 0);

    mx = 0;

    dfs(mn, 0);

    cout << mx;

    return 0;
}
