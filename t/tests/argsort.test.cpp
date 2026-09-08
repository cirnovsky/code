#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
#include "../argsort.hpp"

int main() {
	int N;cin>>N;
	vector<Point<long long>> pts(N);
	for(auto &p:pts)cin>>p.x>>p.y;
	sort(pts);
	for (auto &&p:pts)cout<<p.x<<" "<<p.y<<"\n";
}
