#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7;

struct edge {
  int u, ind;
};

vector<edge> edges[MAXN];
int fout[MAXN];
bool bridge[MAXN];
int used[MAXN], tin[MAXN], tout[MAXN], timer = 1;

void dfs_bridge(int v, int p = -1, int pind = -1) {
    used[v] = 1;
    fout[v] = tin[v] = timer++;
    for(auto e: edges[v]) {
        if(e.u == p && e.ind == pind)
            continue;
        if(!used[e.u]) {
            dfs_bridge(e.u, v, e.ind);
            fout[v] = min(fout[v], fout[e.u]);
            if(tin[v] < fout[e.u])
                bridge[e.ind] = 1;
        }
        else
            fout[v] = min(fout[v], tin[e.u]);
    }
}

int bindex = 0;
void add_edge(int u, int v) {
	
	edge target;
	target.u = u;
	target.ind = bindex;

	edges[u].push_back(target);
	bindex++;

}

int main() {
	int N;
	cin >> N;

	int from[N], to[N];
	for (int i = 0; i < N; i++) {
		cin >> from[N];
		cin >> to[N];
		add_edge(from, to);
	}

	dfs_bridge(0);

	int u,v,M;
	cin >> M;
	char RC;
	for (int i = 0; i < M; i++) {
		cin >> RC;
		cin >> u;
		cin >> v;

		if (RC == 'R') {
			
		}
	}
}