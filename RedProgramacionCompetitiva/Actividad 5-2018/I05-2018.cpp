#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;
int cnt[MAXN];
set<int> ms;
set<int>::iterator it;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int op, y, x, z, t, q, n;
    cin >> t;
    while(t--)
    {
        ms.clear();
   for(int i=0; i<MAXN;i++) cnt[i]=0;
        cin >> n;
        ms.insert(-1);
        ms.insert(100001);
        while(n--)
        {
            cin >> y;
            if(cnt[y]==0) ms.insert(y);
            cnt[y]++;
        }

//        for(it = ms.begin(); it != ms.end(); it++)
//            cout << *it << ' ';
        cin >> q;
        while(q--)
        {
            cin >> op >> y;
            if(op == 1)
            {
                it = ms.upper_bound(y - 1);
                it--;
                x = *it;
                it = ms.upper_bound(y);
                z = *it;

                cout << x << ' ' << z << '\n';
            }else if(op == 2)
            {
                if(cnt[y]==0) ms.insert(y);
                cnt[y]++;
            }
            else if(op == 3)
            {
                if(cnt[y]) cnt[y]--;
                if(cnt[y]==0) ms.erase(y);
            }
        }
    }


    return 0;
}

