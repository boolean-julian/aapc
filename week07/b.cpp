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
double dot(PT a, PT b) {
	return a.x * b.x + a.y * b.y;
}
double norm(PT ab) {
	return sqrt(dot(ab, ab));
}
double dis(PT a, PT b) {
	return norm(b - a);
}

bool cmp(PT a, PT b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

vector<PT> convex_hull(vector<PT> &v) {
	if (v.size() == 1) {
		vector<PT> hull;
		hull.push_back(v[0]);
		return hull;
	}
	sort(v.begin(), v.end(), &cmp);
	PT p1 = v[0], p2 = v.back();
	vector<PT> up, down;
	up.push_back(p1);
	down.push_back(p1);
	int n = (int) v.size();
	for (int i = 1; i < n; ++i) {
		if (i == n - 1 || cw(v[i] - p1, p2 - v[i])) {
			while (up.size() >= 2 &&
						 !cw(up[up.size()-1]-up[up.size()-2], v[i]-up[up.size()-1]))
				up.pop_back();
			up.push_back(v[i]);
		}
		if (i == n - 1 || ccw(v[i] - p1, p2 - v[i])) {
			while (down.size() >= 2 && 
						 !ccw(down[down.size()-1]-down[down.size()-2],
									v[i]-down[down.size()-1]))
				down.pop_back();
			down.push_back(v[i]);
		}
	}

	vector<PT> hull = up;
	for (int i = down.size() - 2; i > 0; --i) {
		hull.push_back(down[i]);
	}
	return hull;
}

int main() {
	int N;
	double C;
	cin >> N >> C;

	PT pt;
	vector<PT> cities;
	double g, gold = 0;
	for (int i = 0; i < N; i++) {
		cin >> pt.x >> pt.y;
		cities.push_back(pt);

		cin >> g;
		gold += g; 
	}

	vector<PT> wall = convex_hull(cities);
	int M = wall.size();
	double length = 0;
	for (int i = 0; i < M; i++) {
		length += dis(wall[i], wall[(i+1)%M]);
	}

	if (gold - length*C >= 0)	cout << "Build that wall!";
	else						cout << "Maybe don't!";
	cout << endl;

}