#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	
	long long in;
	
	for (long long i = 0; i < n; i++) {
		cin >> in;
		if ((in % 3 == 0) != (in % 2 == 0)){
			cout << in;
			cout << " ";
		}
	}
}