/*
    Tablero de Ajedrez
    By tasK!ll
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 101;

char a[MAXN][MAXN][4];
int N;
vector<int> s;

int ok(){
    int changea = 0;
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++){
            if((i & 1 && j & 1) || (!(i & 1) && !(j & 1))){
                changea += (a[i][j][s[0]] == '0');
            }
            else
                changea += (a[i][j][s[0]] == '1');
        }

    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++){
            if((i & 1 && j & 1) || (!(i & 1) && !(j & 1))){
                changea += (a[i][j][s[2]] == '0');
            }
            else
                changea += (a[i][j][s[2]] == '1');
        }

    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++){
            if((i & 1 && j & 1) || (!(i & 1) && !(j & 1))){
                changea += (a[i][j][s[1]] == '1');
            }
            else
                changea += (a[i][j][s[1]] == '0');
        }

    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++){
            if((i & 1 && j & 1) || (!(i & 1) && !(j & 1))){
                changea += (a[i][j][s[3]] == '1');
            }
            else
                changea += (a[i][j][s[3]] == '0');
        }

    return changea;
}

int ok1(){
    int changea = 0;
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++){
            if((i & 1 && j & 1) || (!(i & 1) && !(j & 1))){
                changea += (a[i][j][s[0]] == '1');
            }
            else
                changea += (a[i][j][s[0]] == '0');
        }

    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++){
            if((i & 1 && j & 1) || (!(i & 1) && !(j & 1))){
                changea += (a[i][j][s[2]] == '1');
            }
            else
                changea += (a[i][j][s[2]] == '0');
        }

    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++){
            if((i & 1 && j & 1) || (!(i & 1) && !(j & 1))){
                changea += (a[i][j][s[1]] == '0');
            }
            else
                changea += (a[i][j][s[1]] == '1');
        }

    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++){
            if((i & 1 && j & 1) || (!(i & 1) && !(j & 1))){
                changea += (a[i][j][s[3]] == '0');
            }
            else
                changea += (a[i][j][s[3]] == '1');
        }

    return changea;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    s.push_back(0);
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);

    cin >> N;
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++)
            cin >> a[i][j][0];
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++)
            cin >> a[i][j][1];
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++)
            cin >> a[i][j][2];
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++)
            cin >> a[i][j][3];

    int sol = 4 * N * N;
    //deben haber 2 que empiecen con 0 y 2 comenzando con 1
    do{
        int k = ok();
        if(k < sol) sol = k;
        k = ok1();
        if(k < sol) sol = k;
    }while(next_permutation(s.begin(), s.end()));

    cout << sol;
    return 0;
}

