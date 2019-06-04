#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0), EPS = 1e-12;

struct PT {
    double x, y; 

    PT operator+(const PT &p) const { 
        return {x + p.x, y + p.y}; 
    }
    PT operator-(const PT &p) const { 
        return {x - p.x, y - p.y}; 
    }
    PT operator*(double c) const { 
        return {x * c, y * c}; 
    }
    PT operator/(double c) const { 
        return {x / c, y / c}; 
    }
};
struct Line {
    double a, b, c;
};

Line build(PT p1, PT p2) {
    return {p2.y - p1.y, p1.x - p2.x, p1.y * p2.x - p1.x * p2.y};
}

double val(Line l, PT p) {
    return l.a * p.x + l.b * p.y + l.c;
}

double det(double a1, double b1, double a2, double b2) {
    return a1 * b2 - b1 * a2;
}

bool intersect(int a1, int a2, int b1, int b2) {
    if (a1 > a2)
        swap(a1, a2);
    if (b1 > b2)
        swap(b1, b2);
    return max(a1, b1) <= min(a2, b2);
}
bool intersect(PT a1, PT a2, PT b1, PT b2) {
    Line la = build(a1, a2);
    Line lb = build(b1, b2); 
    return intersect(a1.x, a2.x, b1.x, b2.x) &&
           intersect(a1.y, a2.y, b1.y, b2.y) &&
           val(la, b1) * val(la, b2) <= 0 &&
           val(lb, a1) * val(lb, a2) <= 0;
}

const int MAXN = 1e5;
vector<int> edges[MAXN];
bool path(int s, int t) {
    set<int> todo;
    set<int> done;
    todo.insert(s);
    
    while (!todo.empty()) {
        auto it = todo.begin();
        int q = *it;
        todo.erase(it);
        done.insert(q);
        for (auto e : edges[q]) {
            if (e == t) {
                return true;
            }
            else if (!done.count(e)) {
                todo.insert(e);
            }
        }
    }
    return false;
}

void addedge(int i, int j) {
    edges[i].push_back(j);
    edges[j].push_back(i);
}

const int INFLEN = 1e5;
int main() {
    cout.setf(ios::fixed), cout.precision(8);    
    
    int N;
    vector<PT> from;
    vector<PT> to;

    cin >> N;
    
    double w;
    cin >> w;
    
    from.push_back( {-INFLEN, w});
    to.push_back(   {INFLEN , w});

    from.push_back( {-INFLEN, 0});
    to.push_back(   {INFLEN , 0});

    PT x, y;
    for (int i = 0; i < N; i++) {
        cin >> x.x >> x.y >> y.x >> y.y;
        from.push_back(x);
        to.push_back(y);
    }

    for (int i = 0; i <= N+1; i++)
        for (int j = i+1; j <= N+1; j++)
            if (intersect(from[i], to[i], from[j], to[j]))
                addedge(i,j);

    if (!path(0,1))      cout << 1;
    else                 cout << 0;
    cout << endl;
}
