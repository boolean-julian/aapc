#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001, INF = 1e9;
int cost[MAXN];

long long solve(int n, string& s, string &t) {
	vector<int> remove, add, common;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1')
			sum += cost[i];
		if (s[i] == '1' && t[i] == '0')
			remove.push_back(cost[i]);
		if (s[i] == '0' && t[i] == '1')
			add.push_back(cost[i]);
		if (s[i] == '1' && t[i] == '1')
			common.push_back(cost[i]);
	}
	sort(common.begin(), common.end());
	long long mincost = INF;
	while (1) {
		sort(remove.begin(), remove.end(), greater<int>());
		sort(add.begin(), add.end());
		long long allcost = 0;
		long long tempsum = sum;
		for (int i = 0; i < remove.size(); i++)
			tempsum -= remove[i], allcost += tempsum;
		for (int i = 0; i < add.size(); i++)
			tempsum += add[i], allcost += tempsum;
		mincost = min(mincost, allcost);
		if (common.size() > 0) {
			remove.push_back(common.back());
			add.push_back(common.back());
			common.pop_back();
		}
		else break;
	}
	return mincost;
}
int main() {
	int N;
	string s, t;
	cin >> N >> s >> t;
	for(int i = 0; i < N; i++)
		cin >> cost[i];
	cout << solve(N, s, t) << endl;
}

