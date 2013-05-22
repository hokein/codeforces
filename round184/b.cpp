#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000;

ll data[N];
int n;
bool is_valid = true;

struct info {
  long long a, b;
  info() {}
  info(ll x, ll y) { a = x; b = y; }
};

info dp(int pos) {
  if (pos == n-1)
    return info(data[n-1], 1);

  info t = dp(pos+1);
  if (t.a*data[pos] / t.a !=  data[pos]) // overflow > 10^18
    is_valid = false;
  return info(t.a*data[pos]+t.b, t.a);
}

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a%b);
}
int main() {
  ll p, q;
  while (cin >> p >> q) {
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> data[i];
    is_valid = true;
    info ans = dp(0);
    ll cc = gcd(p, q);
    ll cc2 = gcd(ans.a, ans.b);
    p /= cc;
    q /= cc;
    ans.a /= cc2;
    ans.b /= cc2;
    if (is_valid && p == ans.a && q == ans.b)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } 
  return 0;
} 
