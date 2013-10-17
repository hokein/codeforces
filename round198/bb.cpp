// Vector Cross product
// a x b = |a||b|*sin(thetra)
// |a x b| = det |x1, y1| = x1*y2 - x2*y1.
//               |x2, y2| 
// triangle Area of vector a and b = |a x b|/2 = (x1*y2 - x2*y1)*0.5
//
// Given 3 points (x1, y1), (x2, y2), (x3, y3), calculate triangle formed by the
// three points.
//
// Area = det |x1, y1, 1| or det |(x2-x1), (y2-y1)|
//            |x2, y2, 1|        |(x3-x1), (y3-y1)|
//            |x3, y3, 1|
// Reference:
// http://zh.wikipedia.org/wiki/%E8%A1%8C%E5%88%97%E5%BC%8F#cite_note-autogenerated3-28 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

struct Point {
  int x, y;
  Point() {}
  Point(int x, int y) { this->x = x; this->y = y; }
  friend Point operator-(const Point& a, const Point& b) {
    return Point(a.x - b.x, a.y - b.y);
  }
};

const int N = 10000;
const double epos = 0.00000001;
Point p[N];

// Calculate cross product.
inline double ccw(const Point& p1, const Point& p2) {
  return p1.x*p2.y - p2.x*p1.y;
}

inline double chmax(double a, double b) {
  if (b - a > epos)
    return b;
  return a;
}
int main() {
  //freopen("test.txt", "r", stdin);
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      cin >> p[i].x >> p[i].y;

    double sumArea = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i+1; j < n; ++j) {
        double maxPlus = -1, maxMinus = -1; 
        for (int k = 0; k < n; ++k)
          if (k != i && k != j) {
            double product = ccw(p[k]-p[i], p[k]-p[j]) * 0.5;
            if (product < 0)
              maxMinus = max(maxMinus, -product);
            else
              maxPlus = max(maxPlus, product);
          }

        if (maxPlus > 0 && maxMinus > 0)
          sumArea = max(sumArea, maxMinus+maxPlus);
      }
    printf("%lf\n", sumArea);
    //cout << sumArea << endl;
  }
  return 0;
} 