#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
int reps[MAXN];
int N;

int find_set(int v) {
	return (v == reps[v]) ? v : (reps[v] = find_set(reps[v]));
}

int counter = 1;
bool done = false;
void unite(int a, int b) {
	a = find_set(a); b = find_set(b);
	if (a != b) {
		reps[b] = a;
		counter++;
		if (counter == N) {
			done = true;
		}
	}
}

void create_sets() {
	for (int i = 1; i <= N; i++) {
		reps[i] = i;
	}
}

int main() {
	int M;
	cin >> N >> M;

	create_sets();

	int as[M], bs[M];
	for (int i = 0; i < M; i++) {
		cin >> as[i] >> bs[i];
	}

	for (int i = 0; i < M; i++) {
		unite(as[i], bs[i]);	
		if (done) {
			cout << i+1 << endl;
			return 0;
		}
	}

	cout << "Build some more!" << endl;
	return 0;
}

