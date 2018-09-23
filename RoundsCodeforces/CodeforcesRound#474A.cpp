#include <bits/stdc++.h>

using namespace std;

int a, b, c;

int main(){
    string d;
    cin >> d;

    bool ok = true;

    d = 'a' + d;
    for(int i = 1 ; i < d.size() ; i++) if(d[i] < d[i - 1]) ok = false;
    for(int i = 1 ; i < d.size() ; i++) if(d[i] == 'a') a++;  else if(d[i] == 'b') b++; else c++;

    if(!ok || !b || !a || (b != c && c != a))
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;

}
