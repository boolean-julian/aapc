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

int main() {
	long N;
	cin >> N;

	vector<PT> vertices;
	vector<double> xs;
	vector<double> ys;
	PT pt;
	for (int i = 0; i < N; i++) {
		cin >> pt.x >> pt.y;
		vertices.push_back(pt);
		xs.push_back(pt.x);
		ys.push_back(pt.y);
	}

	double xmin, xmax, ymin, ymax;
	xmin = *min_element(xs.begin(), xs.end());
	ymin = *min_element(ys.begin(), ys.end());
	xmax = *max_element(xs.begin(), xs.end());
	ymax = *max_element(ys.begin(), ys.end());

	double rect = (xmax - xmin)*(ymax - ymin);
	double poly = polygon_trapeze_area(vertices);

	cout.setf(ios::fixed), cout.precision(9);
	cout << poly/rect << endl;
}