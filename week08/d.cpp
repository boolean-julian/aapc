#include<bits/stdc++.h>
using namespace std;

int main() {
	int X;
	cin >> X;

	string q;
	cin >> q;

	int index = 0, diff = 0, failcnt = 0;
	while(index < q.length()) {
		if (diff < X && q[index] == 'W') {
			diff++;
			index++;
			failcnt = 0;
			continue;
		}
		else if (diff > -X && q[index] == 'M') {
			diff--;
			index++;
			failcnt = 0;
			continue;
		}
		else if (index < q.length() - 1 && failcnt < 2) { 
			swap(q[index], q[index+1]);
			failcnt++;
			continue;
		}
		break;
	}

	cout << index << endl;
}

