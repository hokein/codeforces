#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;

const int N = 10000;

int x[N];
P points[N];
int n;

bool intersect(const P& a, const P& b) {
  return a.first < b.first && b.first < a.second && a.second < b.second;
}
int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      cin >> x[i];
    for (int i = 1; i < n; ++i) {
      int a = min(x[i-1], x[i]);
      int b = max(x[i-1], x[i]);
      points[i-1] = P(a, b); 
    }

    bool is_ok = 1;
    for (int i = 0; i < n-1 && is_ok; ++i)
      for (int j = i+1; j < n-1 && is_ok; ++j) {
        if (intersect(points[i], points[j])
            || intersect(points[j], points[i]))
           is_ok = false;
      }
    if (!is_ok)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
} 
