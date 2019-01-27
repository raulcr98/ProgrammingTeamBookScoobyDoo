#include <bits/stdc++.h>

using namespace std;
int N;
char grid[40][40];
int id(char ch){
    if(isdigit(ch)) return ch - '0';
    return ch - 'A' + 10;
}

bool latin()
{
    for(int i = 0 ; i < N; i++){
        int cnt[40] = {0};
        for(int j = 0; j < N; j++)
            ++cnt[id(grid[i][j])];
        for(int k = 0; k < N; k++)
            if(cnt[k] != 1) return false;
    }

    for(int j = 0 ; j < N; j++){
        int cnt[40] = {0};
        for(int i = 0; i < N; i++)
            ++cnt[id(grid[i][j])];
        for(int k = 0; k < N; k++)
            if(cnt[k] != 1) return false;
    }

    return true;
}

bool reduced(){
    int prev = -1;
    for(int i = 0; i < N; i++)
    {
        if(id(grid[i][0]) - 1 != prev || id(grid[0][i]) - 1 != prev)
            return false;
        prev++;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> grid[i];

    if(latin()){
        if(reduced()) cout << "Reduced\n";
        else cout << "Not Reduced\n";
    } else cout << "No\n";
    return 0;
}
