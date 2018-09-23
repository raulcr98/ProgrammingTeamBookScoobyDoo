/*
Sean is trying to save a large file to a USB flash drive. He has n USB flash drives with capacities equal to a1, a2, ..., an megabytes. The file size is equal to m megabytes.

Find the minimum number of USB flash drives needed to write Sean's file, if he can split the file between drives.

Input
The first line contains positive integer n (1 ≤ n ≤ 100) — the number of USB flash drives.

The second line contains positive integer m (1 ≤ m ≤ 105) — the size of Sean's file.

Each of the next n lines contains positive integer ai (1 ≤ ai ≤ 1000) — the sizes of USB flash drives in megabytes.

It is guaranteed that the answer exists, i. e. the sum of all ai is not less than m.

Output
Print the minimum number of USB flash drives to write Sean's file, if he can split the file between drives.
*/

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 5;

int arr[MAXN], N, M;

bool cmp ( int i , int j) {return i > j;}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N, cmp);

    int cnt = 0, i = 0, sum;

    while(i < N && cnt < M)
        cnt += arr[i++];
    cout << i;
    return 0;
}
