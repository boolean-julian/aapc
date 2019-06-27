#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
vector<int> edges[MAXN], requests[MAXN];
int dsu[MAXN], ancestor[MAXN];
bool used[MAXN];

int find_set(int v) {
    return (v == dsu[v]) ? v : (dsu[v] = find_set(dsu[v]));
}

void union_sets(int a, int b, int new_ancestor) {
    a = find_set(a), b = find_set(b);
    if (rand() & 1)
        swap(a, b);
    dsu[a] = b;
    ancestor[b] = new_ancestor;
}

void dfs (int v) {
    dsu[v] = v;
    ancestor[v] = v;
    used[v] = true;
    for (int w : edges[v])
        if (!used[w]) {
            dfs(w);
            union_sets(v, w, v);
        }
    for (int w : requests[v])
        if (used[w])
            printf("%d %d -> %d\n", v, w, ancestor[find_set(w)]);
}

