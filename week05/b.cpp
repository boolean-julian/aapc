#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20, INF = 1000000000;
int dp[1 << MAXN][MAXN], d[MAXN][MAXN];

int dp_tsp(int n) {
    for(int mask = 0; mask < (1 << n); mask++)
        for(int i = 0; i < n; i++) 
            dp[mask][i] = INF;
    for(int i = 0; i < n; i++) {
        int mask = 1 << i;
        dp[mask][i] = 0;
    }
    for(int mask = 0; mask < (1 << n); mask++)
        for(int i = 0; i < n; i++) {
            if(!(mask & (1 << i)))
                continue;
            for(int j = 0; j < n; j++) {
                if(mask & (1 << j))
                    continue;
                int nmask = mask | (1 << j);
                dp[nmask][j] = min(dp[nmask][j], dp[mask][i] + d[i][j]);
            }
        }
    int mask = (1 << n)-1, mindp = INF;
    for(int i = 0; i < n; i++)
        mindp = min(mindp, dp[mask][i]);

    return mindp;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> d[i][j];
        }
    }
        
    cout << dp_tsp(N) << endl;

}