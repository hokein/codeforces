#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll solve(ll n, ll div) {
  if (div > n)
    return 1;
  if (n%div == 0) {
    return solve(n, 3*div);
  }
  else {
    return n/div+1;
  }
}

int main() {
  ll n;
  while (cin >> n) {
    cout << solve(n, 3) << endl;
  }
  return 0;
} 
