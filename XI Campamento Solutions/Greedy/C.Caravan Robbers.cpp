#include <bits/stdc++.h>
using namespace std;

const int MAXN = 150000;

typedef pair<int, int> pii;

int N, x, y;
pii D[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("caravan.in", "r", stdin);
    freopen("caravan.out", "w", stdout);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        D[i] = make_pair(x, y);
    }

    sort(D, D + N);

    double l = 0, r = 1000000, mid, ret = 0;

    for (int it = 0 ; it < 100 ; it++) {
        mid = (l + r) / 2;
        double left = 0;
        int ok = 1;
        for (int i = 0 ; i < N && ok ; i++) {
            if (D[i].first > left)  left = D[i].first;
            if (left + mid > D[i].second)
                ok = 0;
            left += mid;
        }
        if (ok)
            l = mid, ret = mid;
        else
            r = mid;
    }

    int rp = 0, rq = 1;

    for (int p, q = 1 ; q <= N ; q++) {
        p = round(ret * q);

        if (fabs((double) p / q - ret) < fabs((double) rp / rq - ret))
            rp = p, rq = q;
    }

    cout << rp << '/' << rq;

    return 0;
}
