/*
    Sweep Line
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 2 * 1e6 + 1;

typedef pair<LL, LL> pii;

int N, k;
vector<pii> p;
vector<pii> sol;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> k;
    for(int i = 1 ; i <= N ; i++){
        LL a, b;
        cin >> a >> b;
        p.push_back(pii(a + 1000000000, 0));
        p.push_back(pii(b + 1000000000, 1));
    }

    sort(p.begin(), p.end());

    LL c, x, y;
    c = x = y = 0;
    for(int i = 0 ; i < p.size() ; i++){
        if(p[i].second == 0LL){
            c++;
            if(c == k){
                x = p[i].first;
            }
        }
        else{
            if(c == k){
                y = p[i].first;
                sol.push_back(pii(x, y));
                x = y = 0LL;
            }
            c--;
        }
    }

    sort(sol.begin(), sol.end());

    cout << sol.size() << '\n';
    for(int i = 0 ; i < sol.size() ; i++)
        cout << sol[i].first - 1000000000 << ' ' << sol[i].second - 1000000000 << '\n';
	return 0;
}