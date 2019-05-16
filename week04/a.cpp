#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
vector<int> edges[MAXN];

long bfs(int s, int N, int used[]) {
	queue<int> q;
	used[s] = 1;
	q.push(s);

	while(!q.empty()) {
		int v = q.front();
		q.pop();

		for (auto u: edges[v]) {
			if (!used[u]) {
				used[u] = used[v] + 1;
				q.push(u);
			}
		}
	}

	long avg = 0;
	for (int i = 0; i < N; i++)
		if (i != s)
			avg += used[i]-1; 
	return avg;
}

void add_edge(int u, int v) {
	edges[u].push_back(v);
	edges[v].push_back(u);
}

int main() {
	int N,M;
	cin >> N;
	cin >> M;

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u;
		cin >> v;
		add_edge(u-1, v-1);
	}
	
	double s = 0;
	for (int i = 0; i < N; i++) {
		int used[N] = {0};
		s += bfs(i,N,used);
	}
	s = double(N*(N-1)) / s;

	cout << fixed;
	cout << setprecision(6);
	cout << s << "\n";
}