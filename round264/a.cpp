#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
using namespace std;

const int N = 1000;

int x[N], y[N], n, s;

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> s) {
    int ans = -1;
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i];
      if (y[i] == 0) {
        if (s >= x[i])
          ans = max(0, ans);
      } else {
        if (s > x[i])
          ans = max(ans, 100-y[i]);
      }
    }
    cout << ans << endl;
  }
  return 0;
} 
