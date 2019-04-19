#include <bits/stdc++.h>
using namespace std;

long long power(long long base, int expo) {
	long long result = 1;
	for (;;) {
		if (expo & 1)
			result *= base;
		expo >>= 1;
		if (!expo)
			break;
		base *= base;
	}
	return result;
}

long long power(long long base, int expo) {
	long long result = 1;
	for (int i = expo; i > 0; i--) {
		result *= base;
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