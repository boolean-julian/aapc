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

double dot(PT a, PT b) {
    return a.x * b.x + a.y * b.y;
}
double norm(PT ab) {
    return sqrt(dot(ab, ab));
}
double dis(PT a, PT b) {
    return norm(b - a);
}
double angle(PT p) { 
    double angle = atan2(p.y, p.x);
    return (angle >= 0) ? angle : (angle + 2*PI);
}
double angle(PT a, PT b) {
    return acos(dot(a, b) / (norm(a) * norm(b)));
}
bool angle_acute(PT a, PT b) {
    return dot(a, b) > 0;
}
bool angle_obtuse(PT a, PT b) {
    return dot(a, b) < 0;
}


vector<PT> points;
void add_point(double x, double y) {
    PT pt = {x, y};
    points.push_back(pt);
}

PT centroid(int n) {
    PT sum = {0, 0};
    for (auto p : points) {
        sum = sum + p;
    }
    return sum / n;
}   

int main() {
    cout.setf(ios::fixed), cout.precision(8);

    int n;
    cin >> n;

    double a,b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        add_point(a,b);
    }

    PT c = centroid(n);
    //cout << c.x << " " << c.y << endl;
        
    int _first = 2;
    if (dis(c,points[0]) < dis(c,points[1]))
        _first = 1;

    int is_star = 1;
    for (int i = _first; i < n + _first; i += 2) {
        if (!angle_obtuse(points[(i+2)%n] - points[(i+1)%n], points[i%n] - points[(i+1)%n])) {
            is_star = 0;
            break;
        }
        if (!angle_acute(points[(i+1)%n] - points[i%n], points[(i-1)%n] - points[i%n])) {
            is_star = 0;
            break;
        }
        /*
        if (dis(c,points[i%n]) <= dis(c, points[(i-1)%n]) && dis(c,points[i%n]) <= dis(c, points[(i+1)%n])) {
            is_star = 0;
            break;
        }
        */
    }

    cout << is_star << endl;


}