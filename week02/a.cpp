#include <bits/stdc++.h>
using namespace std;

bool pair_compare(pair<long, long> a, pair<long, long> b) {
	double x = (double) a.first/a.second;
	double y = (double) b.first/b.second;
	return (x == y) ? a.first < b.first : x < y;
}

int main() {
	int N, M;
	cin >> N;
	cin >> M;

	long num[N];
	long den[M];
	
	for (int i = 0; i < N; i++)
		cin >> num[i];
	for (int i = 0; i < M; i++)
		cin >> den[i];

	vector<pair<long, long>> ps;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ps.push_back({num[i], den[j]});
		}
	}

	sort(ps.begin(), ps.end(), pair_compare);

	for (int i = 0; i < ps.size(); i++) {
		pair<long,long> curr = ps.at(i);
		cout << curr.first << "/" << curr.second << "\n";
	}

	return 0;
}