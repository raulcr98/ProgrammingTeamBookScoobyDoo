#include <iostream>
using namespace std;

const int MAXN = 5001;

int sol;
int N;
int a[MAXN];

int next(int now){
    int c = 0;
    for(int i = now + 1 ; i <= N ; i++){
        if(a[i] == 1){
            sol += (c / 2);
            return i;
        }
        c++;
    }

    for(int i = 1 ; i <= N ; i++){
        if(a[i] == 1){
            sol += (c / 2);
            break;
        }
        c++;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> N && N){
        int c0 = 0;
        sol = 0;
        for(int i = 1 ; i <= N ; i++){
            cin >> a[i];
            c0 += ((a[i] == 0) ? 1 : 0);
        }

        for(int i = 1 ; i <= N ; i++)
            if(a[i] == 1){
                i = next(i);
                if(i == - 1)
                    break;
                i -= 1;
            }
        if(N == c0)
            cout << (N + 1) / 2 << '\n';
        else
        cout << sol << '\n';
    }

    return 0;
}
/*ok*/
