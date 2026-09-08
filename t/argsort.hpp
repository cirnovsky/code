#include "point.hpp"
#include <cmath>
using namespace std;
template <class T>
void sort(vector<Point<T>> &pts) {
  using P = Point<T>;
  sort(pts.begin(), pts.end(), [&](P &i, P &j) {
    return atan2(i.x, i.y) < atan2(j.x, j.y);
  });
}
