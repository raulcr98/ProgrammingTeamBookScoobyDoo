#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 16005;
const int MAX = 10000;

vector<int>  cuadrados;
int dp[MAXN];
int acum[MAXN][5];



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c=1;

    while(c*c<=MAXN){
        cuadrados.push_back(c*c);
        c++;
    }

    dp[0]=0;
    for(int i=1;i<MAXN;i++){
        dp[i]=MAX;
        for(int j=0, len=cuadrados.size();j<len;j++){
            if(i-cuadrados[j]>=0) dp[i]=min(dp[i],dp[i-cuadrados[j]]+1);
        }
    }
for(int i=1;i<MAXN;i++){
    for(int j=1;j<5;j++)
        acum[i][j]=acum[i-1][j]+(dp[i]<=j);
}
int t,a,b;
cin>>t;
while(t--){
    cin>>a>>b>>c;
    c = min(c, 4);
    cout<<acum[b][c]-acum[a-1][c]<<'\n';
}

    return 0;
}
//   // int may=0;
//  //for(int i=0; i<cuadrados.size();i++)cout<<dp[i]<<'\n';
//
////for(int i=0;i<MAXN;i++ )may=max(may,dp[i]);
////cout<<may;

