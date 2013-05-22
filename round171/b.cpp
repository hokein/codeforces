#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100005;
int n, t;
int a[N], sum[N];

bool isvalid(int len) {
  for (int i = len; i <= n; ++i) {
     if (sum[i] - sum[i-len] <= t)
       return true;
  }
  return false;
}
int main() {

  //freopen("test.txt", "r", stdin);

  while (cin >> n >> t) {
    sum[0] = 0; 
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      sum[i] = sum[i-1] + a[i];
    }
    int l = 1;
    int r = n;
    int mid, ans = 0;
    while (l <= r) {
      mid = (l+r)/2;
      if (isvalid(mid)) {
        l = mid+1;
        ans = mid;
      }
      else {
        r = mid-1;
      }
    }

    cout << ans << endl;
  }
  return 0;
} 
