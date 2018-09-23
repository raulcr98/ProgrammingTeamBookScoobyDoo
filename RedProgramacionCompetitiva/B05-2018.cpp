#include <bits/stdc++.h>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 long long n,a,minimo=1000000009,maximo=0;
   cin>>n;
   while(n--){
    cin>>a;
    minimo=min(minimo,a);
    maximo=max(maximo,a);
    cout<<minimo+maximo<<'\n';
   }


    return 0;
}

