#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
set<int> edges[MAXN];
vector<int> topsort;
int used[MAXN];

void dfs_topsort(int v){
    used[v] = 1;
    //reverse(edges[v].begin(), edges[v].end());
   	//for (auto u = edges[v].begin(); u != edges[v].end(); ++u)
    for (auto u = edges[v].rbegin(); u != edges[v].rend(); ++u)
    	if(!used[*u])
            dfs_topsort(*u);
    topsort.push_back(v);
}

void find_topsort(int n) {
    for(int i = n-1; i >= 0; i--)
    //for (int i = 0; i < n; i++) 
        if(!used[i])
            dfs_topsort(i);
    reverse(topsort.begin(), topsort.end());
}

void add_edge(int u, int v) {
	edges[u].insert(v);
}

int main() {
	int N,M;
	cin >> N;
	cin >> M;

	int a,b;
	for (int i = 0; i < M; i++) {
		cin >> a;
		cin >> b;
		add_edge(a-1,b-1);
	}

	find_topsort(N);

	for (int i = 0; i < N; i++) {
		cout << topsort[i]+1 << " ";
	}
	cout << "\n";
}