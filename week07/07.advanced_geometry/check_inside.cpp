#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-12;

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
bool check_inside(vector<PT> &v, PT p) {
  int n = (int) v.size();
  for (int i = 0; i < n; ++i)
    if (dis(v[i], p) < EPS)
      return true;
  PT pinf = {p.x + INF, p.y + 1};
  bool cnt = 0;
  for (int i = 0; i < n; i++)
    cnt ^= intersect(v[i], v[(i+1)%n], p, pinf);
  return cnt;
}
