#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20, INF = 1000000000;
int d[MAXN][MAXN];

void printmat(int A[20][20], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, e, m;
    cin >> n >> e >> m;

    int c, k, t;
    for (int i = 0; i < n; i++) {
        cin >> c >> k;
        for (int j = 0; j < k; j++) {
            cin >> t;
            d[c-1][t-1] = 1;
        }
    }
    
    
}