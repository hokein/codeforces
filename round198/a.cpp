#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll gcd(ll x, ll y) {
  if (y == 0)
    return x;
  return gcd(y, x%y);
}

int main() {
  //freopen("test.txt", "r", stdin);

  ll x, y, a, b;

  while (cin >> x >> y >> a >> b) {
    ll lcd = x*y/gcd(x, y);
    ll s = a%lcd == 0? a: (a/lcd+1)*lcd;
    if (b < s) {
      cout << 0 << endl;
    }
    else {
      cout << (b-s)/lcd + 1 << endl;
    }
  }
  return 0;
} 
