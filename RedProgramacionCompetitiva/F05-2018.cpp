#include <bits/stdc++.h>

using namespace std;
const int MAXN =1e5+5;

int acum[MAXN][65];
int num[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,t,q,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1; i<=n; i++)
            cin>>num[i];

        for(int i=1;i<=n;i++){
            for(int j=0;j<62;j++)
            acum[i][j]=acum[i-1][j];
        acum[i][num[i]]++;
        }
        cin>>q;
    int suma;
    while(q--){
        cin>>a>>b;
        suma=0;
        for(int i=0; i<62;i++)
            suma+=(acum[b][i]-acum[a-1][i])%2;
        cout<<suma<<'\n';
    }
    }
   


    return 0;
}

