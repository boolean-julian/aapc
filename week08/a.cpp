#include <bits/stdc++.h>
using namespace std;

const int MAXC = 3000;
int ballot[MAXC];
int beats[MAXC][MAXC];

int main() {
	int testcase = 1;
	int B, C;
	do {
		cin >> B >> C;

		fill(ballot, ballot+C, 0);
		for (int i = 0; i < C; i++) {
			fill(beats[i], beats[i]+C, 0);
		}

		for (int i = 0; i < B; i++) {
			for (int j = 0; j < C; j++) {
				cin >> ballot[j];
			}
			for (int j = 0; j < C; j++) {
				for (int k = j+1; k < C; k++) {
					beats[ballot[j]][ballot[k]] += 1;
				}
			}
		}	

		int winner = 0;
		for (int i = 0; i < C; i++) {
			for (int j = 0; j < C; j++) {
				if (beats[i][j] > beats[j][i]) {
					winner = i;
				}
			}
		}

		bool nowinner = false;
		for (int i = 0; i < C; i++) {
			if (beats[i][winner] > beats[winner][i]) {
				nowinner = true;
			}
		}
		
		cout << "Case " << testcase << ": ";
		if (nowinner)		cout << "No Condorcet winner";
		else 				cout << winner;
		cout << endl;

		testcase++;
	} while (B != 0 || C != 0);
}