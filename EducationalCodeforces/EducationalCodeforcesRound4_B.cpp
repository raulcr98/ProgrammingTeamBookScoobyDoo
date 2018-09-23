#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 200000 + 5;

int N;
pii a[MAXN];

int main()
{
    cin >> N;
    for(int i = 1 ; i <= N ; i++){
        int b;
        cin >> b;
        a[i] = pii(b, i);
    }

    sort(a + 1, a + N + 1);

    long long sol = 0;

    for(int i = 2 ; i <= N ; i++)
        sol += abs(a[i].second - a[i - 1].second);

    cout << sol;

    return 0;
}