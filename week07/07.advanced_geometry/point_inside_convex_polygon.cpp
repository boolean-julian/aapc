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
double cross(PT a, PT b) {
  return a.x * b.y - a.y * b.x;
}
double cw(PT a, PT b) {
  return cross(a, b) < -EPS;
}
double ccw(PT a, PT b) {
  return cross(a, b) > EPS;
}


// compare angle of vectors ((1,0) has angle 0, (0,1) has angle pi/2 etc.)
bool cmp_angle(const PT &v1, const PT &v2) {
  return v1.y > 0 && (v2.y > 0 && v1.x * v2.y > v2.x * v1.y ||
                      v2.y == 0 && v2.x < 0 || 
                      v2.y < 0) ||
         v1.y == 0 && (v1.x > 0 && (v2.y != 0 || v2.x < 0) ||
                       v1.x < 0 && v2.y < 0) ||
         v1.y < 0 && v2.y < 0 && v2.x * v1.y < v1.x * v2.y;
}
// requires polygon v in counter-clockwise order
vector<PT> precalc(vector<PT> &v, PT &zero) {
  int n = v.size(), min_i = 0;
  vector<PT> a;
  for (int i = 0; i < n; i++) {
    a.push_back(v[i] - zero);
    if (cmp_angle(a[i], a[min_i]))
      min_i = i;
  }
  rotate(a.begin(), a.begin() + min_i, a.end());
  rotate(v.begin(), v.begin() + min_i, v.end());
  return a;
}
// call with a = precalc(v, zero), p = point to test
bool point_inside_convex_polygon(vector<PT> &v, PT zero, vector<PT> a, PT &p) {
  int n = v.size();
  int ub = upper_bound(a.begin(), a.end(), p - zero, cmp_angle) - a.begin();
  int i1, i2;
  if (ub == n || ub == 0) i1 = n-1, i2 = 0;
  else i1 = ub - 1, i2 = ub;
  return ccw(v[i2] - v[i1], p - v[i1]);
}
