#include <bits/stdc++.h>

using namespace std;

int N, mx, f, l;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b;
   while(cin >> a >> b){
        a++;
        f = a * b - abs(a - b);
        b++;
        a--;
        l = a * b - abs(a - b);

        if(f < l){
            cout << "Interpersonal\n";
        }
        else if(f > l)
            cout << "Technical\n";
        else
            cout << "Either\n";
   }


    return 0;
}
