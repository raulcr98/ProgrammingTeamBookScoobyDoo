/*
    By Guille y Reynier
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    if(n < 6)

    {
        cout << -1 << '\n';
        for(int i = 2; i <= n; ++i)
        {
            cout << 1 << ' ' << i << '\n';
        }
        return 0;
    }


    cout << "1 2\n1 3\n1 4\n";
    for(int  i = 5; i <= n; ++i)
    {
        cout << "2 " << i << '\n';
    }

     for(int i = 2; i <= n; ++i)
        {
            cout << 1 << ' ' << i << '\n';
        }
    return 0;
}