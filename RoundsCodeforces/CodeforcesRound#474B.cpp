#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 100;

long long N, k, a, b, sol;
long long c[MAXN];
priority_queue<long long, vector<long long>, less<long long> > q;

int main(){
    cin >> N >> a >> b;
    k = a + b;
    for(int i = 1 ; i <= N ; i++) cin >> c[i];
    for(int i = 1 ; i <= N ; i++){
        int k;
        cin >> k;
        c[i] = abs(c[i] - k);
        q.push(c[i]);
    }

    while(k > 0){
        long long now = q.top();
        q.pop();
        q.push(abs(now - 1));
        k--;
    }

    while(!q.empty()){
        sol += (q.top() * q.top());
        q.pop();
    }

    cout << sol;
    return 0;

}
