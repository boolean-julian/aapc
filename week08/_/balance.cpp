#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
int v[MAXN], n;

int solve() {
    int prevbalance = 0;
    int balance = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        balance += v[i] - 1;
        if (balance != 0 && !(balance > 0 && prevbalance < 0))
            cnt++;
        prevbalance = balance;
    }
    return cnt;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    cout << solve() << endl;
}

