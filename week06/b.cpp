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

double dot(PT a, PT b) {
    return a.x * b.x + a.y * b.y;
}
double norm(PT ab) {
    return sqrt(dot(ab, ab));
}
double dis(PT a, PT b) {
    return norm(b - a);
}
Line build(PT p1, PT p2) {
    return {p2.y - p1.y, p1.x - p2.x, p1.y * p2.x - p1.x * p2.y};
}
Line normalize(Line l) {
    double len = sqrt(l.a * l.a + l.b * l.b);
    return {l.a / len, l.b / len, l.c / len};
}
double val(Line l, PT p) {
    return l.a * p.x + l.b * p.y + l.c;
}
double dis(Line l, PT p) {
    Line ln = normalize(l);
    return abs(val(ln, p));
}
bool angle_acute(PT a, PT b) {
    return dot(a, b) > 0;
}
double seg_dis(PT a1, PT a2, PT p) {
    if (angle_acute(p - a1, a2 - a1) && 
        angle_acute(p - a2, a1 - a2)) {
        Line l = build(a1, a2);
        return dis(l, p);
    }
    return min(dis(a1, p), dis(a2, p));
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

double ray_dis(PT a1, PT a2, PT p) {
    if (angle_acute(p - a1, a2 - a1)) {
        Line l = build(a1, a2);
        return dis(l, p);
    }
    return dis(a1, p);
}


int main() {
    cout.setf(ios::fixed), cout.precision(6);
    
    PT a1, a2;
    PT b1, b2;

    cin >> a1.x >> a1.y >> a2.x >> a2.y;
    cin >> b1.x >> b1.y >> b2.x >> b2.y;

    // solution for rays
    PT ad = a2 - a1;
    PT bd = b2 - b1;

    double dx = b1.x - a1.x;
    double dy = b1.y - a1.y;
    double det = bd.x * ad.y - bd.y * ad.x;
    
    double u = -1;
    double v = -1;
    if (det != 0) {
        u = (dy * bd.x - dx * bd.y) / det;
        v = (dy * ad.x - dx * ad.y) / det;
    }

    double minimum = 0;
    if (u < 0 || v < 0) {
        minimum = ray_dis(a1, a2, b1);
        minimum = min(ray_dis(a1, a2, b2), minimum);
        minimum = min(ray_dis(b1, b2, a1), minimum);
        minimum = min(ray_dis(b1, b2, a2), minimum);
    }
    cout << minimum << endl;
    
    // solution for segments 
    /*
    double minimum;
    if (intersect(a1, a2, b1, b2)) {
        minimum = 0;
    }
    else {
        minimum = seg_dis(a1, a2, b1);
        minimum = min(seg_dis(a1, a2, b2), minimum);
        minimum = min(seg_dis(b1, b2, a1), minimum);
        minimum = min(seg_dis(b1, b2, a2), minimum);
    }

    cout << minimum << endl;
    */
}



