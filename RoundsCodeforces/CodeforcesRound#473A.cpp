/*
	By tasK!ll
*/

#include <bits/stdc++.h>


using namespace std;

int N;
string a = "Mahmoud\n", b = "Ehab\n";

int main(){
    cin >> N;
    if(N & 1)
        cout << b;
    else
        cout << a;
}