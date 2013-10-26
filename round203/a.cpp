#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000;
int a[N], b[N], n, m;

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m) {
    int min_a, max_a, min_b, max_b;
    max_a = -1;
    min_a = min_b = 101;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      max_a = max(a[i], max_a);
      min_a = min(a[i], min_a);
    }
    for (int j = 0; j < m; ++j) {
      cin >> b[j];
      min_b = min(min_b, b[j]);
    }
    if (min_b <= max_a
        || max(2*min_a, max_a) >= min_b) {
      cout << -1 << endl;
    }
    else {
      cout << max(max_a, 2*min_a) << endl;
    }
  }
  return 0;
} 
