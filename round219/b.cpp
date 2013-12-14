#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll w, m, k;

int dig(ll m) {
  int ret = 0;
  while (m) {
    ++ret;
    m /= 10;
  }
  return ret;
}

ll max_num_dig(int digs) {
  ll ret = 0;
  for (int i = 0; i < digs; ++i)
    ret = 10*ret+9; 
  return ret;
}

ll ppow(int n) {
  ll ret = 1;
  if (n == 1)
    return 0;
  for (int i = 0; i < n-1; ++i)
    ret *= 10;
  return ret;
}

void solve() {
  int m_digits = dig(m);
  ll ans = 0;

  if (w/(m_digits*k) >= max_num_dig(m_digits)-m+1) {
    w -= (max_num_dig(m_digits)-m+1)*k*m_digits;
    ans = max_num_dig(m_digits)-m+1;
  } else {
    ll cnt = w/(m_digits*k);
    w -= cnt*m_digits*k;
    ans = cnt; 
    cout << ans << endl;
    return;
  }
  for (int i = m_digits+1; ; ++i) {
    ll sizes = max_num_dig(i)-ppow(i)+1;
    ll cnt = w/(i*k);
    if (cnt >= sizes) {
      w -= k*sizes*i;
      ans += sizes;
    } else {
      ans += cnt;
      break;
    }
  }
  cout << ans << endl;
}

int main() {
  while (cin >> w >> m >> k)
    solve();
  return 0;
} 
