#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 100005;

ll a[N];
ll sum[N], rsum[N];
int n;

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    for (int i = 1; i <= n; ++i)
      cin >> a[i];

    sum[0] = 0;
    for (int i = 1; i <= n; ++i)
      sum[i] = sum[i-1]|a[i];

    rsum[n] = a[n];
    for (int i = n-1; i >= 1; --i)
      rsum[i] = rsum[i+1]|a[i];

    ll ans = max(sum[n], rsum[1]);

    for (int i = 1; i < n; ++i)
      ans = max(ans, sum[i]^rsum[i+1]);
    cout << ans << endl;    

  }
  return 0;
} 
