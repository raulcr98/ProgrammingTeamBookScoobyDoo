/*
    Teoria de Numeros
    By tasK!ll
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e6 + 2;

bool mk[MAXN], del[MAXN];
vector<int> di[MAXN], sol;
set<int> ok;

void criba(){
    for(int i = 2 ; i < MAXN ; i++){
        if(!mk[i]){
            for(int j = i ; j < MAXN ; j+=i){
                mk[j] = 1;
                di[j].push_back(i);
            }
        }
        ok.insert(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    criba();

    int N;
    cin >> N;

    int a;
    bool o = true;
    for(int i = 1 ; i <= N ; i++){
        cin >> a;

        int now = *ok.begin();

        if(o){
            now = *ok.lower_bound(a);
            if(now != a)
                o = false;
            sol.push_back(now);
        }
        else{
            sol.push_back(now);
        }

        for(int k:di[now]){
            for(int j = k ; j < MAXN ; j+=k){
                if(!del[j]){
                    ok.erase(j);
                    del[j] = 1;
                }
            }
        }
    }

    cout << sol[0];
    for(int i = 1 ; i < sol.size() ; i++)
        cout << " " << sol[i];
    return 0;
}