#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
int ancestor[MAXN];
int depth[MAXN];
vector<int> bktrk[MAXN];

void backtrack(int u) {
	if (bktrk[u].empty()) {
		int ua = u;
		while (ua != 0) {
			bktrk[u].push_back(ua);
			ua = ancestor[ua];
			depth[u] += 1;
		}
	}
}

void add(int a, int b) {
	ancestor[b] = a;
	backtrack(b);
}

void get(int u, int v) {
	if (depth[u] < depth[v]) {
		for (int i = 0; i < depth[u]; i++) {
			for (int j = depth[v]-depth[u]; j < depth[v]; j++) {
				if (bktrk[u][i] == bktrk[v][j]) {
					cout << bktrk[u][i] << endl;
					return;
				}
			}
		}
	}
	else {
		for (int i = 0; i < depth[v]; i++) {
			for (int j = depth[u]-depth[v]; j < depth[u]; j++) {
				if (bktrk[v][i] == bktrk[u][j]) {
					cout << bktrk[v][i] << endl;
					return;
				}
			}
		}
	}
}

int main() {
	backtrack(1);
	
	int K;
	cin >> K;

	for (int i = 0; i < K; i++) {
		string query;
		cin >> query;

		int a,b;
		if (query == "GET") {
			cin >> a >> b;
			get(a,b);
		}
		else if (query == "ADD") {
			cin >> a >> b;
			add(a,b);	
		}
	}
}