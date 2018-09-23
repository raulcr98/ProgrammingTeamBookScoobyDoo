#include <bits/stdc++.h>

using namespace std;

long long num[2005];

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    int n;
    while(cin>>n)
    {
        for(int i=0; i<n; i++)cin>>num[i];
        long long sol=0;

        for(int i=0; i<n; i++)
        {
            long long best=0;
           long long besta=-1000000009;
            for(int j=i; j<n; j++)
            {
                best=max(num[j],best+num[j]);
                besta=max(best,besta);
                sol^=besta;
            }
        }
        cout<<sol<<'\n';

    }
    return 0;
}

