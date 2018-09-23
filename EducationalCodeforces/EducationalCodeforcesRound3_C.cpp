/*

In the school computer room there are n servers which are responsible for processing several computing tasks. You know the number of scheduled tasks for each server: there are mi tasks assigned to the i-th server.

In order to balance the load for each server, you want to reassign some tasks to make the difference between the most loaded server and the least loaded server as small as possible. In other words you want to minimize expression ma - mb, where a is the most loaded server and b is the least loaded one.

In one second you can reassign a single task. Thus in one second you can choose any pair of servers and move a single task from one server to another.

Write a program to find the minimum number of seconds needed to balance the load of servers.
Input

The first line contains positive number n (1 ≤ n ≤ 105) — the number of the servers.

The second line contains the sequence of non-negative integers m1, m2, ..., mn (0 ≤ mi ≤ 2·104), where mi is the number of tasks assigned to the i-th server.
Output

Print the minimum number of seconds required to balance the load.
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int a[MAXN], b[MAXN], sum, sol, n;

int piso(){
    return sum / n;
}

int techo(){
    return sum / n + 1;
}

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum % n == 0){
        for(int i = 1 ; i <= n ; i++){
            sol += (a[i] > sum / n) ? (a[i] - (sum / n)) : 0;
        }
        cout << sol;
    }
    else{
        sort(a + 1, a + 1 + n);
        for(int i = n ; i >= 1 ; i--) b[n - i + 1] = a[i];
        for(int i = 1 ; i <= n ; i++){
            if(i <= (sum % n)) sol += abs(b[i] - techo());
            else sol += abs(b[i] - piso());
        }
        cout << sol / 2;
    }
    return 0;
}