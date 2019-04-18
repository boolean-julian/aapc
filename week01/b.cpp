#include <bits/stdc++.h>
using namespace std;

int main() {
	unsigned long long p;
	cin >> p;

	int counter = 0;
	for (int i=0; i < 64; i++) {
		if (p % 2 == 1) {
			counter += 1;
		}
		p = p >> 1;
	}

	cout << counter << "\n";
}