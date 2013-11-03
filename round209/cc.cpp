// calulate all remain[i] = a1+a2+...+a[i-1]+a[i]+...+an, 1<=i<=n, missing a[i], sum-a[i]
//
// find min(remain[i]), each remain[i] is different.
// if there are multiple remain[i] are the same, combine them, count the 'cnt' times
// if cnt%x == 0, add cnt/x elements: remain[i]+1 at the end.
//
// Toturial:
// Obviously, the answer is xv. Let sum = a1 + a2 + ... + an. Also let
// si = sum - ai (the array of degrees). After that let's find value v by the 
// following algorithm: Let's consider a sequence of degrees as decreasing sequence.
// Now we will perform the following operation until it's possible to perfom it.
// Take the minimum degree v from the array of degrees and calculate the number of 
// elements cnt, which have the same degree. If cnt multiples of x, then replace
// all cnt elements by cnt / x elements of the form v + 1. Since the sequence of 
// degrees is a decreasing sequence, we can simply assign them to the end. If cnt
// is not a multiple of x, then we found the required value v. Also you need to
// check, that v is not greater then sum. Otherwise, v will be equals to sum. 
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 10000000;
const ll MOD = 1000000000+7;
ll mini[N], a[N], x, n;

ll pow_mod(ll x, ll cnt) {
  if (cnt == 0)
    return 1;
  ll half = pow_mod(x, cnt/2);
  ll res = (half*half)%MOD;
  if (cnt % 2 == 1)
    res = (res*x)%MOD;
  return res; 
}

int main() {
  while (cin >> n >> x) {
    ll maxx = 0;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
    }
    for (int i = 0; i < n; ++i)
      mini[i] = sum-a[i];

    sort(mini, mini+n);
    reverse(mini, mini+n);
    for (int i = n-1; i >= 0; ) {
      int j = i-1;
      ll times = 1;
      while (j >= 0 && mini[j] == mini[i]) {
        ++times;
        --j;
      }
      if (times%x == 0) {
        ll value = mini[i]+1;
        for (int k = 0; k < times/x; ++k)
          mini[++j] = value; 
      } else {
        cout << pow_mod(x, min(sum, mini[i])) << endl;
        break;
      }
      i = j;
    }
  }
  return 0;
} 
