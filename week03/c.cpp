#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
vector<int> edges[MAXN];
int used[MAXN], tin[MAXN], fout[MAXN], timer;
bool cutpoint[MAXN];

void dfs_cutpoint(int v, bool root = true) {
    used[v] = 1;
    fout[v] = tin[v] = ++timer;
    cutpoint[v] = false;
    int fwd_edges = 0;
    for(auto u: edges[v])
        if(!used[u]){
            dfs_cutpoint(u, false);
            fout[v] = min(fout[v], fout[u]);
            if(tin[v] <= fout[u] && !root)
                cutpoint[v] = true;
            fwd_edges++;
        }
        else
            fout[v] = min(fout[v], tin[u]);
    if(root && fwd_edges >= 2)
        cutpoint[v] = true;
}

void identify(int* a, bool* cutpoint, int N) {
    int c = 0;
    stringstream ss;
    for (int i = 0; i < N; i++) {
        if (cutpoint[i]) {
            ss << i+1 << " ";
            c++;
        }
    }
    cout << c << "\n" << ss.str() << "\n";
}

void add_edge(int u, int v) {
    edges[u].push_back(v);
    edges[v].push_back(u);
}

int main() {
    int N,M;
    cin >> N;
    cin >> M;

    int a[M],b[M];
    for (int i = 0; i < M; i++) {
        cin >> a[i];
        cin >> b[i];
        add_edge(a[i]-1,b[i]-1);
    }
    
    dfs_cutpoint(0);
    identify(b, cutpoint, N);
}