#include <bits/stdc++.h>
using namespace std;

int main() {
	// Buckets, Balls, Bets
	int N, M, B;
	cin >> N;
	cin >> M;
	cin >> B;

	multiset<int> buckets;
	int bucket_index[M];
	for (int i = 0; i < M; i++) {
		cin >> bucket_index[i];
		buckets.insert(bucket_index[i]);
	}

	int bucket;
	int amount;
	int location;
	bool location_flag;
	for (int i = 0; i < B; i++) {
		cin >> bucket;
		cin >> amount;

		bool location_flag = true;
		for (int j = 0; j < amount; j++) {
			cin >> location;
			if (bucket_index[location-1] != bucket) {
				location_flag = false;
			}
		}

		cout << ((location_flag && amount == buckets.count(bucket)) ? "CORRECT" : "INCORRECT") << endl;
	}
}