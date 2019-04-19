#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	int M;

	cin >> N;
	cin >> M;

	int list[N];
	int i, j;
	for (i = 0; i < N; i++) {cin >> list[i];}

	int query;
	bool found;
	for (i = 0; i < M; i++) {
		cin >> query;
		
		found = false;
		for (j = 0; j < N; j++) {
			if (query == list[j]) {
				found = true;
				cout << j+1 << " ";
			}
		}
		if (!found) {cout << "None!";}
		cout << "\n";
	}
}