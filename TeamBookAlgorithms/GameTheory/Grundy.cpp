#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100004;

typedef long long ll;

int t, n, x;
ll sol, aux, val, grundy[MAXN];
bool  marcado[MAXN];

int main()
{
	for(int k = 0; k <= 3; k++) grundy[k]=k;

	for(int i = 4 ; i <= 10000 ; i++){ 
		memset(marcado,0,(i + 2) * sizeof(bool));
		for(int j = 1 ; j <= i / 2 ; j++)
			for(int k = 0 ; k < 3 ; k++) 
				marcado[ (grundy[j - 1] ^ grundy[i - j - k]) ] = true;

		x = 0;
		while(marcado[x]) 
			x++;
		grundy[i] = x;
	}

	cin >> t;
	while(t--){
		cin >> n;
		sol = 0;
		
		for(int i = 0 ; i < n ; i++){
			cin >> aux;
			sol ^= grundy[aux];
		}

		if(!sol) cout << "SLAVKO\n";
		else cout<<"MIRKO\n";
	}
	
	return 0;
}
