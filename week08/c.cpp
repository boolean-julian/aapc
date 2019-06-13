#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;

int used[MAXN];
vector<int> edges[MAXN];

bool intersect(int l1, int r1, int l2, int r2) {
	return true ? (r2 >= l1 && l2 <= r1) : false;
}

bool intersect(int l, int r, int p) {
	return true ? (p >= l && p <= r) : false;
}

void addedge(int u, int v) {
	edges[u].push_back(v);
	edges[v].push_back(u);
}

void bfs(int s) {
	queue<int> q;
	used[s] = 1;
	q.push(s);
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(auto u: edges[v]) 
			if(!used[u]) {
				used[u] = used[v] + 1;
				q.push(u);
			}
	}
}

int main() {
	int M;
	cin >> M;

	vector<int> l;
	vector<int> r;
	int a,b,size = -1;
	do {
		cin >> a >> b;
		l.push_back(a);
		r.push_back(b);
		size++;
	} while (a != 0 || b != 0);

	for (int i = 0; i < size; i++) {
		for (int j = i+1; j < size; j++) {
			if (intersect(l[i],r[i],l[j],r[j])) {
				addedge(i+2,j+2);
				//cout << i+2 << " " << j+2 << endl;
			}
		}
		if (intersect(l[i],r[i],0)) {
			addedge(0, i+2);
			//cout << 0 << " " << i+2 << endl;
		}
		if (intersect(l[i],r[i],M)) {
			addedge(1, i+2);
			//cout << 1 << " " << i+2 << endl;
		}
	}

	bfs(0);
	int result = used[1]-2;
	if (result > 0) 	cout << result << endl;
	else 				cout << "No solution" << endl;
}