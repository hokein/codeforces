#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

const int N = 1000000;

ll num[N];

inline ll gcd(ll a, ll b) {
  return b == 0? a : gcd(b, a%b);
}

int main() {
  //freopen("test.txt", "r", stdin);
  int n;
  while (cin >> n) {
    ll sum1 = 0;
    for (int i = 0; i < n; ++i) {
      cin >> num[i];
      sum1 += num[i];
    }
    sort(num, num+n);
    ll sum2 = 0, sum_before = num[0];
    for (int i = 1; i < n; ++i) {
      sum2 += num[i]*(i) - sum_before;
      sum_before += num[i];
    }
    ll sum = sum1 + 2LL*sum2; 
    ll g = gcd(sum, n);
    cout << sum/g << " " << n/g << endl;; 
  }

  return 0;
} 
