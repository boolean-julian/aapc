#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e8;

int n, a[MAXN], t[MAXN];

void inc(int i, int delta) {
  for (; i < n; i = (i | (i+1)))
    t[i] += delta;
}

void init(){
  for (int i = 0; i < n; i++)
    inc(i, a[i]);
}

int sum(int r) {
  int result = 0;
  for (; r >= 0; r = (r & (r+1)) - 1)
    result += t[r];
  return result;
}

int sum(int l, int r) {
  return sum(r) - sum(l-1);
}

int main() {
	int N, M;
	cin >> N >> M;

	n = 2*N-1;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N-1; i++) {
		a[i+N] = a[i];
	}

	init();

	char c;
	int l,r;
	
	int offset = 0;
	for (int i = 0; i < M; i++) {
		cin >> c;
		if (c == 'q') {
			cin >> l >> r;
			cout << sum(l-1+offset, r-1+offset) << endl;
		}
		if (c == 'r') {
			offset = (1+offset)%N;
		}
	}
}