#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7;
vector<int> edges[MAXN];
int used[MAXN], tin[MAXN], tout[MAXN], timer = 1;

void dfs(int v){
	used[v] = 1;
	tin[v] = timer++;
	for(auto u: edges[v])
		if(!used[u])
			dfs(u);
	tout[v] = timer++;
}
bool ancestor(int u, int v) {
	return tin[u] < tin[v] && tout[u] > tout[v];
}
void add_edge(int u, int v) {
	edges[u].push_back(v);
}

int main() {
	int N;
	cin >> N;

	string names[N];
	for (int i = 0; i < N; i++) {
		getline(cin >> ws, names[i]);
	}

	int j;
	for (int i = 0; i < N; i++) {
		cin >> j;
		if (j != 0)
			add_edge(j-1, i);
	}

	dfs(N-1);

	int queries, a, b;
	cin >> queries;
	for (int i = 0; i < queries; i++) {
		cin >> a;
		cin >> b;
		
		if (ancestor(a-1, b-1))
			cout << names[b-1] << " is an ancestor of " << names[a-1] << ".\n";
		else if (ancestor(b-1, a-1))
			cout << names[a-1] << " is an ancestor of " << names[b-1] << ".\n";
		else
			cout << names[a-1] << " and " << names[b-1] << " are not related.\n";
	}
}
