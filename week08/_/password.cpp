#include <bits/stdc++.h>
using namespace std;

int cnta[128], cntb[128], alen;

bool solve(const string &a, const string &b) {
    for (int i = 0; i < b.length(); i++)
        cntb[b[i]]++;
    for (int i = 0; i < b.length(); i++)
        if (++cnta[a[i]] <= cntb[a[i]])
            alen++;
    for (int beg = 0, end = b.length(); end <= a.length(); beg++, end++) {
        if (alen == b.length())
            return true;
        if (end < a.length() && ++cnta[a[end]] <= cntb[a[end]])
            alen++;
        if (cnta[a[beg]]-- <= cntb[a[beg]])
            alen--;
    }
    return false;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
}

