#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const ll N = 10000;

inline int cal(int x, int n, int p) {
  if (n == 0)
    return 1;
  if (n == 1)
    return x;
  int half = cal(x,n/2, p);
  if (n%2 != 0)
    return (((half*half)%p)*x)%p;
  return ((half%p)*(half%p))%p;
}

inline bool isvalid(int x, int n, int p) {
  return cal(x,n,p) == 1;
}

int main() {
  ll p;
  while (cin >> p) {
    int ans = 0;
    for (int x = 1; x < p; ++x) {
      bool ok = isvalid(x, p-1, p);
      for (int i = 1; i < p-1 && ok; ++i)
        ok = !isvalid(x, i, p);
      if (ok)
        ans++;
    }
    cout << ans << endl;
  }
  return 0;
} 
