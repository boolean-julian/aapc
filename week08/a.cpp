#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int a[MAXN];

int main() {
    int testcase = 1;
    int b, c;
    while (1) {
        cin >> b >> c;
        fill(a, a+c, 0);

        if (b == 0 && c == 0)
            break; 

        int ct;
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < c; j++) {
                cin >> ct;
                a[ct] += j;
            }
        }

        cout << "Case " << testcase << ": ";

        int index = 0;      
        for (int i = 1; i < c; i++) {
            if (a[i] < a[index])
                index = i;
        }

        bool minexists = true;
        for (int i = 0; i < c; i++) {
            if (i != index && a[index] == a[i]) {
                minexists = false;
            }
        }

        if (minexists)      cout << index << endl;
        else                cout << "No Condorcet winner" << endl;
        testcase++;
    }
}