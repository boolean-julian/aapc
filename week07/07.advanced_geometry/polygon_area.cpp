#include <bits/stdc++.h>
using namespace std;

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

double polygon_triangle_area(vector<PT> &v, PT p) {
  int n = (int) v.size();
  double sum = 0;
  for (int i = 0; i < n; ++i){
    int j = i + 1 < n ? i + 1 : 0;
    sum += cross(v[i] - p, v[j] - p);
  }
  return abs(sum) / 2;
}

double polygon_trapeze_area(vector<PT> &v) {
  int n = (int) v.size();
  double sum = 0;
  for (int i = 0; i < n; ++i){
    int j = i + 1 < n ? i + 1 : 0;
    sum += (v[i].x - v[j].x) * (v[i].y + v[j].y);
  }
  return abs(sum) / 2;
}



