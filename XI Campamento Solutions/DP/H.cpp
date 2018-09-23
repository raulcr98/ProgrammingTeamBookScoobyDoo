#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4005;

int N;
vector<int> arr;
int dp[MAXN];


int main() {
    //ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x;
    cin >> N ;

    for(int i = 0; i < 3; i++) {
        cin >> x;
        bool fla = false;
        for(int j = 0; j < arr.size(); j++)if(arr[i] == x)fla = true;
        if(!fla)arr.push_back(x);
    }

    sort(arr.begin(),arr.end());

    // int sol = f(N) << '\n';

    for(int j = 0; j < arr.size(); j++)
        for(int i = arr[j]; i <= N; i++)
            if((i-arr[j])==0 || dp[i-arr[j]])
            dp[i] = max(dp[i], dp[i - arr[j]] + 1);

    cout << dp[N] << '\n';
    return 0;
}

