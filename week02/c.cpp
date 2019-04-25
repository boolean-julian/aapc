#include <bits/stdc++.h>
using namespace std;

int main() {
	//cout << ("Hello" < "Hell") << endl;
	int N, M;
	cin >> N;
	cin >> M;

	set<string> words;
	string temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		words.insert(temp);
	}

	string first, next, last;
	bool isempty;
	for (int i = 0; i < M; i++) {
		cin >> first;
		next = string({char(first[0] + 1)});
		cin >> last;

		/*
		for (auto a : words) {
			cout << a << " ";
		}*/

		isempty = true;
		auto lo = words.lower_bound(first);
		auto hi = words.lower_bound(next);
		for (auto it = lo; it != hi; it++) {
			if ((*it).back() == last[0]) {
				cout << *it << " ";
				isempty = false;
			}
		}

		if (isempty) cout << "Empty category!";
		cout << endl;
	}
}