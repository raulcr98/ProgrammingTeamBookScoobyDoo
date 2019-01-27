#include <bits/stdc++.h>

using namespace std;

bool f(int N, int a, int b){
    int sum = 0, t = 1;
    while(sum < N){
        if(t) sum += a;
        else sum += b;
        t ^= 1;
    }
    return sum == N;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<pair<int, int> > ans;
    for(int i = 2; i < N; i++){
        if(f(N, i, i - 1)) ans.push_back(make_pair(i, i - 1));
        if(f(N, i, i)) ans.push_back(make_pair(i, i));
    }
    cout << N << ":\n" << ans[0].first << "," << ans[0].second << "\n";
    for(int i = 1; i < ans.size(); i++)
        cout << ans[i].first << "," << ans[i].second << "\n";
    return 0;
}
