
//Edmond Karp O(N*N*M)

#define x first
#define y second

const int MAXN = 105;

int N, M;
bool mk[MAXN * 2];
bool mt[MAXN * 2][MAXN * 2];//Red de Flujo
int ft[MAXN * 2];//Padre de cada nodo para la reconstrucción

bool EdmondK(){

    fill(ft, ft + MAXN * 2, -1);
    fill(mk, mk + MAXN * 2, 0);

    queue<int> Q;
    Q.push(0);
    mk[0] = true;

    while(!Q.empty()){
        int nod = Q.front();
        Q.pop();

        if(nod == N + M + 1)
            break;

        for(int i = 0 ; i <= N + M + 1 ; i++){
            if(!mk[i] && mt[nod][i]){
                mk[i] = true;
                ft[i] = nod;
                Q.push(i);
            }
        }
    }

    if(ft[N + M + 1] < 1)
        return false;

    int nod = N + M + 1;
    while(ft[nod] != -1){
        mt[ft[nod]][nod] -= 1;
        mt[nod][ft[nod]] += 1;
        nod = ft[nod];
    }

    return 1;
}

//while(EdmondK()) 
//	sol++;
//  mientras exista un camino aumentas la solucion