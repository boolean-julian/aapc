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

double len;
Line normalize(Line l) {
    len = sqrt(l.a * l.a + l.b * l.b);
    return {l.a / len, l.b / len, l.c / len};
}
double val(Line l, PT p) {
    return l.a * p.x + l.b * p.y + l.c;
}
double dis(Line l, PT p) {
    Line ln = normalize(l);
    return abs(val(ln, p));
}
double det(double a1, double b1, double a2, double b2) {
    return a1 * b2 - b1 * a2;
}
bool parallel(Line l1, Line l2) {
    return abs(det(l1.a, l1.b, l2.a, l2.b)) < EPS;
}
bool equivalent(Line l1, Line l2) {
    return abs(det(l1.a, l1.b, l2.a, l2.b)) < EPS &&
           abs(det(l1.c, l1.b, l2.c, l2.b)) < EPS &&
           abs(det(l1.a, l1.c, l2.a, l2.c)) < EPS;
}
bool intersect(Line l1, Line l2, PT& p) {
    double val = det(l1.a, l1.b, l2.a, l2.b);
    if (abs(val) < EPS)
        return false;
    p.x = -det(l1.c, l1.b, l2.c, l2.b) / val;
    p.y = -det(l1.a, l1.c, l2.a, l2.c) / val;
    return true;
}

int main() {
    cout.setf(ios::fixed), cout.precision(8);    

    double a,b,c,R;
    cin >> a >> b >> c >> R;

    Line l = normalize({a,b,c});
    
    cout << l.a << " " << l.b << " " << l.c+R << endl;
    cout << l.a << " " << l.b << " " << l.c-R << endl;

}

