#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1015;

int dp[MAXN][MAXN];


int LCS(string a, string b){
memset(dp,0,sizeof(dp));
a=" "+a;
b=" "+b;
int la=a.length(),lb=b.length();

  for(int i = 1 ; i < la ; i++)
            for(int j = 1 ; j < lb ; j++)
                if(a[i] == b[j])dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

        return dp[la-1][lb-1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    freopen("r.in", "r", stdin);
string a,b;
    while(getline(cin, a)){
     getline(cin, b);
     cout<<LCS(a,b)<<'\n';

    }

    return 0;
}
//asdasdasd
