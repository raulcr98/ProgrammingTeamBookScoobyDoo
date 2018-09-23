#include <bits/stdc++.h>

using namespace std;
bool cmp(int a, int b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int lista[n];


    for(int i = 0; i < n; i++)cin >> lista[i];

    sort(lista, lista + n, cmp);
    vector<int> sol;

    for(int i = 0; i < n; i += 2) sol.push_back(lista[i] - lista[i + 1]);

    sort(sol.begin(), sol.end(),cmp);
    int suma = 0;

    for(int i = 0; i < n / 2; i++) suma += sol[i];
    //cout<<"suma "<<suma<<'\n';

    int pos = 0, tot = 0;

    while(pos < n / 2 && tot <= suma-tot) {
            tot+=sol[pos++];
    }



    if(tot==(suma-tot)) cout << "-1\n";
    else cout << (n/2 - pos)<< "\n";

    return 0;
}
/*ok*/
