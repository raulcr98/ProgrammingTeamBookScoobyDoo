#include <bits/stdc++.h>

using namespace std;

string d;
bool ok = false;
int c;

int main(){
    cin >> d;
    d = d[0] + d;
    for(int i = 1 ; i < d.size() ; i++) {
            if(d[i] == d[i - 1]) c++;
            else c = 1;
            if(c == 7) ok = true;
    }

    if(!ok)
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;

}
