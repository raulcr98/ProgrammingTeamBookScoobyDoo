/*
papa, la idea es que inicialmente tienes n * m conjuntos disjuntos (cada cuadrito del grid), y vas a ir disminuyendo cada haces una union, pero los cuadros negros no los vas a unir, o sea vas a tener los cuadros negros como si también fijarán disjuntos. Entonces, si a la cantidad de conjuntos disjuntos le quitas la cantidad de cuadros negros que hay, eso t da la cantidad real de regiones que hay.
Pa hacer to eso hay que empezar de atrás pa lante, pq si lo haces en pierdes la estructura del disjoint set. Entonces... lo que hice fue pintar los cuadros de las consultas, cuento las regiones y los cuadros negros, y después voy de atrás pa alante quitando consultas (disminuyendo la cantidad de cuadros negros y uniendo los blancos q van quedando) y por supuesto, guardando los resultados
*/ 

#include <bits/stdc++.h>
using namespace std;

const int MAXQ = 1e4 + 5;
const int MAXN = 1e3 + 5;


//Esto es pa guardar la información d cada consulta
struct query
{
	int x1, x2, y1, y2;
	query(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0)
	{
		x1 = _x1;
		x2 = _x2;
		y1 = _y1;
		y2 = _y2;
	}

};

query q[MAXQ];
int p[MAXN * MAXN], sz[MAXN * MAXN];
int ttime[MAXN][MAXN];    //pa saber en qué momento hice cada consulta
bool blk[MAXN][MAXN];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int sets, cntblk, N, M, Q;
// sets es la cantidad de disjoint sets y cntblk es contador de negras

//estos son las funciones normales del disjoint set
void make_sets(int n)
{
	sets = n;
	for(int i = 0; i <= n; i++) p[i] = i, sz[i] = 1;
}

int find(int x)
{
	if(x == p[x]) return x;
	return p[x] = find(p[x]);
}

void union_sets(int a, int b)
{
	a = find(a), b = find(b);
	if(a != b)
	{
		sets--;
		if(sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		p[b] = a;
	}
}


//Esto es pa convertir las cordenadas a posiciones del array del disjoint set
int id(int x, int y){return x*M + y;}


//Esto método es pa pintar
void paint(int x1, int y1, int x2, int y2, int t)
{
	int i = x1, j = y1;
	while(i <= x2 && j <= y2)
	{
		blk[i][j] = true;
		if(ttime[i][j] == -1) ttime[i][j] = t;
		if(x1 == x2) j++;
		else i++;
	}
}

//pa validar los adyacentes
bool valid(int x, int y) { 
	return (x >= 0 && x < N && y >= 0 && y < M);
}


//esto es pa virar pa tras las consultas
void back(int x1, int y1, int x2, int y2, int t)
{
	int i = x1, j = y1;
	while(i <= x2 && j <= y2)
	{
		if(ttime[i][j] == t)//Si el cuadro se pintó en la consulta q estoy quitando
		{
			cntblk--; //disminuyo la cantidad de negras
			for(int k = 0; k < 4; k++) // y lo uno a las regiones blancas vecinas.... si hay...
			{
				int x = i + dx[k];
				int y = j + dy[k];
				if(valid(x, y) && !blk[x][y]) 
					union_sets(id(i, j), id(x, y));
			}
			blk[i][j] = false; // la pintó otra vez de blanca
		}
		if(x1 == x2) j++;
		else i++;
	}
}

int main()
{
	memset(ttime, -1, sizeof ttime);
	scanf("%d%d%d", &M, &N, &Q);
	for(int i = 0; i < Q; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
		q[i] = query(x1 - 1, y1 - 1, x2 - 1, y2 - 1);
	}
	
	for(int i = 0; i < Q; i++)
	{
		paint(q[i].x1, q[i].y1, q[i].x2, q[i].y2, i);
	}
	
	make_sets(N*M);
	cntblk = 0;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(blk[i][j]) cntblk++;
			else
			{
				if(i + 1 < N && !blk[i + 1][j]) 
					union_sets(id(i, j), id(i + 1, j));
				if(j + 1 < M && !blk[i][j + 1])
					union_sets(id(i, j), id(i, j + 1));
			}
		}
	}
	
	vector<int> ans;
	for(int i = Q - 1; i >= 0; i--)
	{
		ans.push_back(sets - cntblk);
		back(q[i].x1, q[i].y1, q[i].x2, q[i].y2, i);
	}
	
	for(int i = Q -  1; i >= 0; i--) printf("%d\n", ans[i]);
	return 0;
}   