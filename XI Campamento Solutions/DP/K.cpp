#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> ijdc;

const int MAXN = 55;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int visit[MAXN][MAXN];
int N, M,len;

string t[MAXN], word;
ijdc S;

bool valid(int i, int j)
{
    return (i >= 0 && i < N && j >= 0 && j < M);
}

int bfs()
{
    memset(visit, -1, sizeof visit);
    S.first = ii(0, 0);
    S.second = ii(0, 0);
    //cout<<"esta es S inicial "<<S.second.X<<" "<<S.second.Y<<"\n";
    queue<ijdc> q;
    q.push(S);
    while(!q.empty())
    {
        S = q.front();
        q.pop();
        int i = S.first.X;
        int j = S.first.Y;
        int d= S.second.first;
        int c = S.second.second ;

        if(c==len)
            return d;

//                cout<<i<<" "<<j<<" "<<d<<" "<<c<<'\n';

        if(t[i][j] == word[c])
        {
            q.push(ijdc(ii(i, j), ii(d + 1, c+1)));
            if(visit[i][j]<c) visit[i][j]=c;
            //memset(visit,0,sizeof(visit));
            //visit[i][j]=true;
        }
        else
        {
            for(int k = 0; k < 4; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                while(valid(x, y) && t[x][y] == t[i][j])
                {
                    x += dx[k];
                    y += dy[k];
                }
                if(valid(x, y) && visit[x][y] < c)
                {
                    visit[x][y] = c;
                    q.push(ijdc(ii(x, y), ii(S.second.first + 1, c)));
                }
            }
        }
    }
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> N >> M)
    {
        for(int i = 0; i < N; i++)
            cin >> t[i];
        cin >> word;
        word = word + '*';
        len=word.length();
        cout<<bfs()<<'\n';
    }

    return 0;
}

