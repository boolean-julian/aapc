#include <bits/stdc++.h>
using namespace std;

const int MAXB = 500, MAXC = 2500;
int a[MAXC];
int m[MAXC][MAXB];


int main() {
	int testcase = 1;
	int b, c;
	do {
		cin >> b >> c;
		fill(a, a+c, 0);

		for (int i = 0; i < b; i++) {
			fill(m[i], m[i]+c, 0);
			for (int j = 0; j < c; j++) {
				cin >> a[j]; 
			}
			for (int j = 0; j < c; j++) {
				for (int k = j+1; k < c; k++) {
					m[a[j]][a[k]] += 1;
				}
			}
		}

		cout << endl;
		for(int i = 0; i < c; i++) {
			for (int j = 0; j < c; j++) {
				cout << m[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		int p = 0, i = 0;
		bool nowinner = false;
		while(i < c) {
			if (m[i][p] > m[p][i]) {
				p = i;
				i = 0;
			}
			i++;
		}

		cout << p << endl;
		/*
		cout << "Case " << testcase << ": ";
		if (nowinner) 	cout << "No Condorcet winner." << endl;
		else 			cout << p << endl;
		*/
		testcase++;
	} while (b != 0 || c != 0);
}