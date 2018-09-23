#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll fac[6005];
const ll mod=1e9+7;

ll egcd(ll a, ll b, ll &x, ll &y)
{
    if(b == 0 )
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = egcd(b, a%b, x, y);
    x -= a / b * y;
    swap(x, y);
    return d;
}


ll modinv(ll a, ll m)
{
    ll x, y, d = egcd(a, m, x, y);
    if(d !=1 ) return -1;
    return (x < 0) ? (x + m) : x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll aux=1;
    fac[0]=1;
    for(ll i=1; i<6005; i++)
    {
        aux*=i;
        aux%=mod;
        fac[i]=aux;
    }

    ll n,suma=0;
    cin >> n;
    ll A=0,B=1,C,D;
    for(ll i=0; i<n; i++)
        for(ll j=0; j<n; j++)
        {
            C = fac[i+j+n-1];
            D = (fac[i] * fac[j])%mod;
            D *= fac[n - 1];
            D%=mod;

            A*=D;
            A%=mod;
            A += C*B;
            A%=mod;

            B*=D;
            B%=mod;
            // aux *= modinv(()%mod, mod) % mod;
        }
    suma = A * (modinv(B,mod)%mod);
    suma%=mod;
    suma*=3;
    suma%=mod;
    cout<<suma<<'\n';

    return 0;
}
