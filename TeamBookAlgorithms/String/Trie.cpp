/*
    Busca si una palabra esta en el diccionario
    Tiempo: O(N) N: Tamaño de la entrada.
*/

#include <bits/stdc++.h>

using namespace std;

const int ALPH = 26;

int N;

struct node {
	node *next[ALPH];
	int mk;
} root;

int main()
{
	cin >> N;
	for(int i = 1; i <= N; i++) {
		string s; 
		cin >> s;

		node *k = &root;

		for(int j = 0; j < s.size(); j++) {
			int p = s[j] - 'a';

			if(k -> next[p] == NULL)
				k -> next[p] = new node();
			k = k -> next[p];
		}

		k -> mk = 1;
	}

	cin >> N;
	for(int i = 1; i <= N; i++) {
		string s; 
		cin >> s;

		node *k = &root;
		bool loc = true;

		for(int j = 0; j < s.size(); j++) {
			int p = s[j] - 'a';

			if(k -> next[p] == NULL) {
				loc = false;
				break;
			}

			k = k -> next[p];
		}

		if(loc && k -> mk) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}
