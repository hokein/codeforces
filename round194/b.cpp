#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 100;

struct Point {
  int x;
  int y;
};

struct Point p[N];

bool cmp(const Point& a, const Point& b) {
  if (a.x != b.x)
    return a.x < b.x;
  return a.y < b.y;
}

bool check() {
  if (!(p[0].x == p[1].x && p[1].x == p[2].x))
    return false;
  if (!(p[0].y < p[1].y && p[1].y < p[2].y))
    return false;

  if (!(p[3].x > p[2].x && p[3].x == p[4].x))
    return false;
  if (!(p[3].y < p[4].y))
    return false;

  if (!(p[5].x == p[6].x && p[6].x == p[7].x && p[5].x > p[3].x))
    return false;
  if (!(p[5].y < p[6].y && p[6].y < p[7].y))
    return false;
  
  return (p[0].y == p[3].y) && (p[3].y == p[5].y) && (p[1].y == p[6].y)
         && (p[2].y == p[4].y) && (p[4].y == p[7].y);
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> p[0].x >> p[0].y) {
    for (int i = 1; i < 8; ++i) {
      cin >> p[i].x >> p[i].y;
    }
    sort(p, p+8, cmp);

    if (check()) 
      cout << "respectable" << endl; 
    else
      cout << "ugly" << endl;
  }
  return 0;
} 
