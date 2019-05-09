#include <bits/stdc++.h>
using namespace std;

int main() {
	int N = 600000;
	multiset<int> storage;
	
	int amount = 0;
	multiset<int>::iterator it = storage.begin();
	string temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;

		if (temp[0] == '#') {
			if (amount > 0) {
				it = storage.begin();
				advance(it, int(0.667*amount));
				cout << *it << endl;
				storage.erase(it);
				amount--;
			}
		}
		else {
			storage.insert(stoi(temp));
			amount++;
		}
	}
}