#include <bits/stdc++.h>

using namespace std;
const int MAXN=1e6 + 5;

int p[MAXN],num[MAXN],tam[MAXN];


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
p[0]=0;
num[0]=-1;
int n,pila,oper,number,padre;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>pila>>oper;
    if(oper==0){
        cin>>number;
        p[i]=pila;
        num[i]=number;
        tam[i]=tam[pila]+1;
        cout<<tam[i]<<'\n';
    }else{
    padre=p[pila];
    cout<<num[pila]<<'\n';
    num[i]=num[padre];
    padre=p[padre];
    p[i]=padre;
    if(num[pila]!=-1) tam[i] = tam[pila]-1;
    }
}

    return 0;
}

