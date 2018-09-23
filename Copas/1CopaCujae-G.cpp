#include <bits/stdc++.h>

using namespace std;

int N;

void rectan(int a, int b){
    for(int i = 1 ; i <= b ; i++){
        for(int j = 1 ; j<= a ; j++)
            cout << '*';
        cout << '\n';
    }
}

string row(int a, int i){
    int k = (a - i) / 2;
    string l = "", ll = "";
    for(int j = 0 ; j < k ; j++)
        l += '.';
    for(int j = 1 ; j <= i ; j++)
        ll += '*';
    return l + ll + l;
}

void triangle(int a){
    for(int i = 1 ; i <= a ; i++)
        if(a >= i * 2 - 1)
        cout << row(a, i * 2 - 1) << '\n';
        else
            break;
}

void triangleinv(int a){
    int as = a - 2;
    int cp = a - as;
    while(as >= 1){
    for(int i = 1 ; i <= cp / 2 ; i++)
        cout << '.';
    for(int i = 1 ; i <= as ; i++)
        cout << '*';

    for(int i = 1 ; i <= cp / 2 ; i++)
        cout << '.';

    cp += 2;
    as -= 2;
    cout << '\n';
    }
}

void rombo(int a){
    triangle(a);
    triangleinv(a);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> N;
    for(int i = 1 ; i <= N ; i++){
        char a;
        int b, c;
        cin >>  a >> b;

        if(a == 'R'){
            cin >> c;
            rectan(b, c);
        }
        else if(a == 'S'){
            rectan(b, b);
        }
        else if(a == 'T'){
            triangle(b);
        }
        else
            rombo(b);
        if(i != N)
            cout << '\n';
    }

    return 0;
}
