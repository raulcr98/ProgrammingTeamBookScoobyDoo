#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

string a;
stack<int> to;
int sol;

char other(char b){
    if(b == '}')
        return '{';

    if(b == ']')
        return '[';

    if(b == '>')
        return '<';

    if(b == ')')
        return '(';
}

int main()
{
    cin >> a;

    for(int i = 0 ; i < a.length() ; i++){
        if(a[i] == '{' || a[i] == '(' || a[i] == '<' || a[i] == '['){
            to.push(i);
        }
        else if(!to.empty()){
            if(other(a[i]) != a[to.top()])
                sol++;
            to.pop();
        }
        else {
            cout << "Impossible\n";
            return 0;
        }
    }
    if(!to.empty())
        cout << "Impossible\n";
    else
        cout << sol << '\n';

    return 0;
}