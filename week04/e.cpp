#include <bits/stdc++.h>
using namespace std;

const int MAXN 	= 1000;
const int SIDES = 6;

char cubes[MAXN][SIDES];
vector<int> index[MAXN];

int main() {
	int N;
	cin >> N;

	char c[SIDES];
	for (int i = 0; i < N; i++) {
		cin >> c;
		for (int j = 0; j < SIDES; j++) {
			cubes[i][j] = c[j];	
		}
	}

	char name[MAXN];
	cin >> name;
	int k = 0;
	while (name[k] != '\0') {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < SIDES; j++) {
				if (name[k] == cubes[i][j]) {
					index[k].push_back(i);
				}
			}
		}
		k++;
	}

	k = 0;
	while (name[k] != '\0') {
		if ( find(index[k].begin(), index[k].end(), k) ) 
	}


}