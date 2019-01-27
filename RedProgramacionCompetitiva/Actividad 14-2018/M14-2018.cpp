#include <bits/stdc++.h>

using namespace std;

int N, mx, f, l;

bool ok(int a){
    while(a > 0){
        if(a % 10 == 0) return 0;
        a /= 10;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    do{
        N++;
    }while(!ok(N));
    cout << N << '\n';
    return 0;
}
