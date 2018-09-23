//LIS O(NlogN)
#include <bits/stdc++.h>

using namespace std;

typedef vector<int>::iterator inti;

const int MAXN = 1001;

int T, N;
int A[MAXN];

int main()
{
    cin >> T;

    while(T--){
        cin >> N;

        for(int i = 1 ; i <= N ; i++)
            cin >> A[i];

        vector<int> LIS;

        LIS.push_back(A[1]);

        for(int i = 2 ; i <= N ; i++){
            inti p = lower_bound(LIS.begin(), LIS.end(), A[i]);

            if(p == LIS.end())
                LIS.push_back(A[i]);

            else if(*p > A[i])
                *p = A[i];
        }

        cout << LIS.size() << '\n';
    }
    return 0;
}
