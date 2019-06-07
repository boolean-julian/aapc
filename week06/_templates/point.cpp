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

int main() {
    cout.setf(ios::fixed), cout.precision(8);
        
}

