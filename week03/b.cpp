#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7;

int n; // number of nodes
vector<int> adj[MAXN]; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void IS_BRIDGE(int v, int to) {
	cout << "Edge from " << v << " to " << to << " is a bridge.\n";
}

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges(int n) {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i);
    }
}

void add_edge(int u, int v) {
	adj[u].push_back(v);
}

int main() {
	int N;
	cin >> N;

	int from[N], to[N];
	for (int i = 0; i < N; i++) {
		cin >> from[i];
		cin >> to[i];
		add_edge(from[i], to[i]);
	}

	find_bridges(N);
	cout << "oof";
	/*
	for (int i = 0; i < 30; i++) {
		cout << bridge[i] << "\n";
	}
	*/

	/*
	int u,v,M;
	cin >> M;
	char RC;
	for (int i = 0; i < M; i++) {
		cin >> RC;
		cin >> u;
		cin >> v;

		if (RC == 'R') {
			
		}
	}*/
}