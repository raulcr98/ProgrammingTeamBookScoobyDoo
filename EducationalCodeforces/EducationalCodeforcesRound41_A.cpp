#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1001;

int ta[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    for(int i = 1 ; i <= M ; i++){
        int a;
        cin >> a;
        ta[a]++;
    }
    cout << *min_element(ta + 1, ta + 1 + N);
    return 0;
}
