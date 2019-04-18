#include <bits/stdc++.h>
using namespace std;

int main() {
	short N;
	short M;

	cin >> N;
	cin >> M;

	int list[N];
	short i, j;
	for (i = 0; i < N; i++) {cin >> list[i];}

	long long query;
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
	}
}