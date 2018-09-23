#include <bits/stdc++.h>

using namespace std;

int inter[]= {700,745, 750,835, 840,925, 930,1015, 1020,1105, 1110,1155, 100,145, 150,235, 240,325, 330,415, 420,505, 510,555};
bool solve(int x){
    for(int i=1; i<24; i+=2)
        if(x<inter[i]&&x>=inter[i-1])return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string g;
    cin>>g;
    int a=0;
    for(int i=0; i<g.length(); i++)
    {
        if(g[i]>='0'&& g[i]<='9')
        {
            a*=10;
            a+=g[i]-'0';
        }
    }
    if(solve(a))
        cout<<"Students, Surprise Quiz!\n";
    else cout<<"Students, you may go out.\n";
    return 0;
}
