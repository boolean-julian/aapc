#include <bits/stdc++.h>
using namespace std;

struct interval {
	int lo, hi, dist;
};

vector<int> L, R;
vector<interval> project_intervals(int N, int M) {
	vector<interval> intervals;
	for (int i = 0; i < L.size(); i++) {
		if ((L[i] >= N || R[i] >= N) && (L[i] <= M || R[i] <= M)) {
			int plo = max(L[i],N);
			int phi = min(R[i],M);
			int pdi = phi-plo;
			if (pdi > 0 && plo == N) {
				intervals.push_back({plo, phi, pdi});
			}
		}
	}
	return intervals;
}

int counter = 0;
bool ok	= true;
void solve(int N, int M) {
	vector<interval> intervals = project_intervals(N, M);
	if (intervals.size() == 0) {
		ok = false;
		return;
	}
	counter++;
	auto maxit = max_element(intervals.begin(), intervals.end(),
			[] (const interval& a, const interval& b) {
					return a.dist < b.dist;
			}
	);
	if ((*maxit).dist == M-N) 	return;
	if ((*maxit).hi != M)		solve((*maxit).hi, M);
}

int main() {
	int M;
	cin >> M;

	int a,b;
	cin >> a >> b;

	while (a != 0 || b != 0) {
		L.push_back(a);
		R.push_back(b);
		cin >> a >> b;
	}
	
	solve(0, M);
	if (ok) 	cout << counter << endl;
	else 		cout << "No solution" << endl;
}