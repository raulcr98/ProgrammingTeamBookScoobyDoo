#include <bits/stdc++.h>

using namespace std;

const int MAXN = 501;

int la, lb;
string A, B;
int ed[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;

    la = A.size() , lb = B.size();
    A = ' ' + A , B = ' ' + B;

    for(int i = 1 ; i <= max(la, lb) ; i++)
        ed[i][0] = ed[0][i] = i;

    for(int i = 1 ; i <= la ; i++)
        for(int j = 1 ; j <= lb ; j++){
            if(A[i] == B[j])
                ed[i][j] = ed[i - 1][j - 1];
            else{
                ed[i][j] = min(ed[i][j - 1], min(ed[i - 1][j], ed[i - 1][j - 1])) + 1;
                if(A[i] == B[j - 1] && B[j] == A[i - 1])
                    ed[i][j] = min(ed[i][j], ed[i - 2][j - 2] + 1);
            }
        }

    cout << ed[la][lb];

    return 0;
}

/* The valid edit operations are: Insert a single character at any position. Modify an existing character in any position. Remove an existing character from any position. Transposition of two existing and adjacents characters from any positions*/