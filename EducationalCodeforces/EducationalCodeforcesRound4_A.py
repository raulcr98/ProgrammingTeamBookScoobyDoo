#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 101;

bool mk[MAXN];
int N, p, q, cp, ccp, cq, ccq;
string a;

int main()
{
    cin >> N >> p >> q;
    cin >> a;
//    N = 8;
//    p = 1;
//    q = 1;
//    a = "aaaaaaaa";

    for(int pp = 0 ; pp <= N ; pp++){
        for(int qq = 0 ; qq <= N ; qq++){
        if(qq * q + pp * p == N){
            cp = pp;
            cq = qq;
            ccp = cp;
            ccq = cq;
            cout << cp + cq << '\n';
            string now = "";
            int cant = 0;
            for(int i = 0 ; i < a.size() && cp ; i++){
                cant++;
                now += a[i];
                if(cant == p){
                    cant = 0;
                    cout << now << '\n';
                    now = "";
                    cp--;
                }
            }
            cant = 0;
            now = "";
            for(int i = ccp * p ; i < a.size() && cq ; i++){
                cant++;
                now += a[i];
                if(cant == q){
                    cant = 0;
                    cout << now << '\n';
                    now = "";
                    cq--;
                }
            }
            return 0;
        }
        }
}
    cout << -1;
    return 0;
}