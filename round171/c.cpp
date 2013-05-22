#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100005;
int n, m;
int a[N], b[N], c[N], sum[N];

bool check(int t, int l, int r) {
  return t-b[t]+1 <= l && t+c[t]-1 >= r;
}
bool isvalid(int ll, int rr) {
  int l = ll;
  int r = rr;
  while (l <= r) {
    int mid = (l+r) / 2;
    if (check(mid, ll, rr))
      return true;
    else if (mid - b[mid] + 1 <= ll)
      l = mid+1;
    else 
      r = mid-1;
  }
  return false;
}
int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m) {
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }

    b[1] = 1;
    for (int i = 2; i <= n; ++i) {
      if (a[i] >= a[i-1])
        b[i] = b[i-1]+1;
      else
        b[i] = 1;
    }

    c[n] = n;
    for (int i = n; i >= 2; --i) {
      if (a[i-1] >= a[i])
        c[i-1] = c[i]+1;
      else
        c[i-1] = 1;
    } 

    int l, r;
    for (int i = 0; i < m; ++i) {
      cin >> l >> r;
      if (isvalid(l, r))
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
  return 0;
} 
