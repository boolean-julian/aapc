#include <bits/stdc++.h>
using namespace std;

int main() {
	// Buckets, Balls, Bets
	int N, M, B;
	cin >> N;
	cin >> M;
	cin >> B;

	map<int, int> ball;
	int temp;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		ball[i] = temp;
	}

	int bucket;
	int amount;
	int location;
	bool flag;
	for (int i = 0; i < B; i++) {
		cin >> bucket;
		cin >> amount;

		bool flag = true;
		for (int j = 0; j < amount; j++) {
			cin >> location;
			if (ball[location-1] != bucket) {
				flag = false;
			}
		}
		cout << (flag ? "CORRECT" : "INCORRECT") << endl;
	}
}