#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 10000;

bool isPrime[N];

void makePrime() {
  memset(isPrime, true, sizeof(isPrime));
  isPrime[1] = false;
  for (int i = 2; i < N; ++i)
    if (isPrime[i])
      for (int j = i*2; j < N; j+=i)
         isPrime[j] = false;
}

int gcd(int a, int b) {
  if (a%b == 0)
    return b;
  return gcd(b, a%b);
}

ll p;

ll cal(ll x, ll n) {
  ll res = 1;
  for (ll i = 0; i < n; ++i)
    res *= x;
  return res;
}

inline bool isvalid(int x, int n, int p) {
  int res = x%p;
  for (int i = 1; i < n; ++i)
    res = (res*x)%p;
  return res%p == 1;    
}

bool check(int x) {
  bool ok = true;
  for (ll i = 1; i < p-1 && ok; ++i)
     ok = !isvalid(x, i, p);
  return ok;
}
int main() {
  makePrime();
  //freopen("test.txt", "r", stdin);


  
  while (cin >> p) {
    int ans = 0;
    for (int i = 2; i < p; ++i)
      if (gcd(i,p) == 1 && isPrime[i]) {
        if (check(i))
        //cout << i << " ";
        ans++;
      }
    //cout << endl;
    cout << ans << endl;
  }
  return 0;
} 
