#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;
double a[7], S;
double f(double i, double p){
    double y = (3.5 - S +  i * p) / p;
    return abs(i - y);
}
int main() {
    cout << setprecision(3) << fixed;
    double ans = 1e9;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 1; i <= 6; i++) { cin >> a[i]; S += i*a[i];}
    for(int i = 1; i <= 6; i++){

        ans = min(ans, f(i, a[i]));
    }
    cout << ans << "\n";
}
