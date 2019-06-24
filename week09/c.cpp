#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6, MAXLOG = 19, INF = 1e9;
int sparse[MAXLOG][MAXN];
int logsize[MAXN];

map<int,int> students;

void build(int n) {
	int c = 2;
	for (int k = 1; k < MAXLOG; k++) {
		for (int i = 0; i + (1 << k) < n; i++)
			sparse[k][i] = min(sparse[k-1][i], sparse[k-1][i + (1<<(k-1))]);
		while (c <= min(2 << k, n))
			logsize[c++] = k;
	}
}

int get(int l, int r) {
	if (l > r)
		return INF;
	int lg = logsize[r - l + 1];
	return min(sparse[lg][l], sparse[lg][r - (1<<lg) + 1]);
}

int getstudent(int l, int r) {
	
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> sparse[0][i];
		students.insert({sparse[0][i], i});
	}
	
	build(N);
	
	int a,b;
	string s;
	int student;
	while(1) {
		cin >> s;
		if (s == "QUESTION") {
			cin >> a >> b;
			student = students[get(a-1,b-1)];		
			cout << student+1 << endl;
		}
		else if (s == "DROPOUT") {
			cin >> a;
			if (a == -1) {
				return 0;
			}
		}
	}
}