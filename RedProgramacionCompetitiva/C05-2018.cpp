#include <bits/stdc++.h>

using namespace std;
string g;
int k;
const int MAXN=1e7+5;

bool primo[MAXN];

void buscaPrimos()
{
    primo[0]=primo[1]=true;
    for(int i=2; i<MAXN; i++)
        if(!primo[i])
            for(int j=2*i; j<MAXN; j+=i) primo[j]=true;
}

bool solve(){
int len=g.length();
int aux;
for(int i=0;i<len;i++){
    aux=0;
    for(int j=0;j<k;j++){
        aux*=10;
        aux+=(int)(g[i]-'0');
        i++;
    }
    if(primo[aux])return false;
    i--;
}
return true;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
buscaPrimos();
while(cin>>k){
    cin>>g;
    if(solve())cout<<":)\n";
    else cout<<":(\n";
}

    return 0;
}

