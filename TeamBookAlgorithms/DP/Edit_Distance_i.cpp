#include <bits/stdc++.h>

using namespace std;

const int MAXN = 502;
string A, B;
int M[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;

    A = " " + A;
    B = " " + B;

    int la = A.size();
    int lb = B.size();

    for(int i = 1 ; i <= max(la, lb) ; i++)
        M[i][0] = M[0][i] = i;

    for(int i = 1 ; i <= la ; i++)
        for(int j = 1 ; j <= lb ; j++){
            if(A[i] == B[j])
                M[i][j] = M[i - 1][j - 1];
            else {
                M[i][j] = min(M[i - 1][j], M[i][j - 1]);
                M[i][j] = min(M[i][j], M[i - 1][j - 1]);
                M[i][j]++;
            }
        }

    cout << M[la - 1][lb - 1] << '\n';
    return 0;
}

/* The valid edit operations are: Insert a single character at any position. Modify an existing character in any position. Remove an existing character from any position. */
