#include <bits/stdc++.h>
using namespace std;

int power(int base, int expo) {
	long long result = 1;
	while (expo > 0) {
		result = result * (long long)(base);
		expo--;
	}
	return result;
}

int main() {
	short T;
	cin >> T;

	int expo;
	int base;

	long long result;
	for (int i = 0; i < T; i++) {
		cin >> base;
		cin >> expo;

		cout << power(base,expo);
		cout << "\n";
	}
}