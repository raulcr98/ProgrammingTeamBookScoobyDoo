#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

string str;

int mod(int a, int m)
{
    a %= m;
    if(a < 0)
        a += m;
    return a;
}


int solve()
{
    str.insert(str.begin(), 'a');
    str.push_back('a');
    int n = str.size(), ret = 0;
    priority_queue<int> mayores, menores;
    for(int i = 0; i < n - 1; i++){
        int dist = mod(str[i] - str[i + 1], 26);
        if(dist){
            mayores.push(dist);
            menores.push(-dist);
        }
    }
    int cnt = mayores.size();

    while(cnt)
    {
        ret++;
        int menor = -menores.top(); menores.pop();
        int mayor = mayores.top(); mayores.pop();

        menor--;
        if(menor) menores.push(-menor);
        else cnt--;

        mayor++;
        mayor %= 26;

        if(mayor) mayores.push(mayor);
        else cnt--;
    }


    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> str)
    {
        if(str[0] == '*') break;
       int ans = solve();
       cout << ans << '\n';
    }
    return 0;
}
//Raul es loca
