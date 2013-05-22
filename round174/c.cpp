// d[i] = a[i+1] - a[i]
// d[1], d[2], ..., d[len-1], a[len]
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int MAX = 2000000;
ll d[MAX];

int main() {

  ll n, k, a, x;
  int op;
  while (cin >> n) {
    ll last = 0;
    ll len = 1;
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
      cin >> op;
      switch (op) {
        case 1:
          cin >> a >> x;
          sum += a*x;
          if (a < len)
            d[a] -= x;
          else
            last += x;
          break;
        case 2:
          cin >> k;
          d[len] = k-last;
          last = k;
          sum += k;
          ++len;
          break;
        case 3:
          sum -= last;
          last = last - d[len-1];
          --len;
          break;
      }
      printf("%.6lf\n", (sum)/(double)len);
    }
  }
  return 0;
} 
