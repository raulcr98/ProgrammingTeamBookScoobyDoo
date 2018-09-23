/*
    pii: pair<int, int>
    ad[MAXN]: vector<pii> 
*/

priority_queue<pii> Q;
Q.push(pii(0, 1));

while(!Q.empty()){
    int nod = Q.top().second;
    int c = Q.top().first;

    Q.pop();

    if(mk[nod])
        continue;

    mk[nod] = true;
    sol += c;

    for(int i = 0 ; i < ad[nod].size() ; i++)
        if(!mk[ad[nod][i].second])
            Q.push(ad[nod][i]);
}
