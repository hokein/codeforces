#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

string s;
void solve() {
  int pos = 1;

  ll ans = 1;
  bool is_find = true;
  while (pos < s.size()) {
    int cnt = 1;
    while (pos < s.size() && s[pos]+s[pos-1] == 9) {
      is_find = true;
      ++cnt;
      ++pos;
    }
    if (cnt % 2 == 1) {
      ans *= (cnt/2+1);
    }
    ++pos;
  }
  if (is_find)
    cout << ans << endl;
  else
    cout << 0 << endl;
}
int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> s) {
    for (int i = 0; i < s.size(); ++i)
      s[i]-='0';
    solve();
  }
  return 0;
} 
