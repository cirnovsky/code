#include "bits/stdc++.h"

using namespace std;
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x−axis in interval [−pi , pi ]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes d i s t ()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated ’a ’ radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

template <class T>
void sort(vector<Point<T>> &pts) {
  using P = Point<T>;
  auto sector = [&](const P&p) {
    if (p.y < 0) return 0;
    else if (p.y == 0 && p.x >= 0) return 1;
    if (p.y > 0) return 2;
    return 3;
  };
  sort(pts.begin(), pts.end(), [&](const P &i, const P &j) {
    int f = sector(i), g = sector(j);
    return f == g ? i.cross(j) > 0 : f<g;
  });
}

int main() {
	int N;cin>>N;
	vector<Point<long long>> pts(N);
	for(auto &p:pts)cin>>p.x>>p.y;
	sort(pts);
	for (auto &&p:pts)cout<<p.x<<" "<<p.y<<"\n";
}
