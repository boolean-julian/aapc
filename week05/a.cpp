#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;
int dp[1 << MAXN], d[MAXN][MAXN];

int dp_matching(int n) {
    dp[0] = 1;
    int maxw = 0;
    for(int mask = 0; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++) {
            if(!(mask & (1 << i)))
                continue;
            for(int j = 0; j < n; j++) {
                if(!(mask & (1 << j)))
                    continue;
                int smask = mask ^ (1 << i) ^ (1 << j);
                dp[mask] = max(dp[mask], dp[smask] & d[i][j]);
            }
        }
        if(dp[mask]) {
            int w = 0;
            for(int i = 0; i < n; i++)
                w += (mask >> i) & 1;
            maxw = max(maxw, w);
        }
    }
    return maxw;
}


int main() {
    int N;
    cin >> N;

    string str[N];
    for (int i = 0; i < N; i++) {
        cin >> str[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i+1; j++) {
            if (str[i][j] == 'Y') {
                d[i][j] = 1;
                d[j][i] = 1;
            }
        }
    }

    cout << dp_matching(N) << endl;
}