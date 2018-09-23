#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=1e5+5;
ll cont[maxn],dp[maxn];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll x,n;
    cin>>n;
    while(n--){
        cin>>x;
        cont[x]++;
    }
    dp[1]=cont[1];
    for(ll i=2;i<maxn;i++)
    dp[i]=max(dp[i-1],i*cont[i]+dp[i-2]);

        cout<<dp[maxn-1]<<'\n';
    return 0;
}

