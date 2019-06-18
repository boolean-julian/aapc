#include <bits/stdc++.h>
using namespace std;

bool contains(int lo, int hi, int p) {
	return (lo <= p && hi >= p);
}

vector<int> pts;
int pivot;
int sorted_search(int lo, int hi) {
	int counter = 0;
	bool setpivot = true;
	for (int i = pivot; i < pts.size(); i++) {
		if (pts[i] > lo && pts[i] < hi) {
			counter++;
			if (setpivot) {
				pivot = i;
				setpivot = false;
			}
		}
		if (pts[i] >= hi) {
			break;
		}
	}
	return counter;
}

int main() {
	int N, W, L, R;
	cin >> N >> W >> L >> R;

	int p;
	for (int i = 0; i < N; i++) {
		cin >> p;
		pts.push_back(p);
	}

	if (R-L < W) {
		cout << -1 << endl;
	}
	else {
		sort(pts.begin(), pts.end());

		int minimum = 1e9;
		int current;
		for (int hi = L+W, lo = L; hi <= R; hi++, lo++) {
			current = sorted_search(lo, hi);
			if (current < minimum) {
				minimum = current;
			}
		}

		cout << minimum << endl;
	}
}