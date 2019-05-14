#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7;
struct edge {
  int u, ind;
  bool ok = true;
};
vector<edge> edges[MAXN];
int tin[MAXN], used[MAXN], fout[MAXN], timer;
int bridge[MAXN] = {0};

void dfs_bridge(int v, int p = -1, int pind = -1) {
    used[v] = 1;
    fout[v] = tin[v] = timer++;
    for(auto e: edges[v]) {
    	if (e.ok) {
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
}

int bindex;
int M = 400;
void add_edge(int v, int u) {
	edge uedge, vedge;

	bindex = min(u,v)*M + max(u,v);

	uedge.u = u;
	uedge.ind = bindex;

	vedge.u = v;
	vedge.ind = bindex;

	edges[u].push_back(vedge);
	edges[v].push_back(uedge);
}

void remove_edge(int bind) {
	fill(bridge.begin(), bridge.end(), 0);
	int u = bind / 400;
	int v = bind % 400;
	edges[u][v].ok = false;
	edges[v][u].ok = false;
}

int main() {
	int N;
	cin >> N;

	int from, to;
	for (int i = 0; i < N; i++) {
		cin >> from;
		cin >> to;
		add_edge(from, to);
	}

	dfs_bridge(from);
	
	int u,v,M,bind;
	cin >> M;
	char RC;
	for (int i = 0; i < M; i++) {
		cin >> RC;
		cin >> u;
		cin >> v;

		if (RC == 'R') {
			bind = min(u,v)*400 + max(u,v);
			if (bridge[bind]) {
				cout << "Impossibile!\n";
			}
			else {
				cout << "Va bene!\n";
				remove_edge(bind);
				dfs_bridge(from);
			}
		}

		//else if (RC == 'C')
	}
}