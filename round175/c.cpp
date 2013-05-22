#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int MAX = 1000000;

ll data[MAX];
int n;

ll my_abs(ll x) {
  return x > 0?x:-x;
}
int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    for (int i = 0; i < n; ++i) 
      cin >> data[i];
    sort(data, data+n);
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
      ans += my_abs(data[i-1]-i);
    cout << ans << endl;
  }
  return 0;
} 
