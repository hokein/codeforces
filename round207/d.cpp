// TLE
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll n, m;
string s1, s2;

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a%b);
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m) {
    cin >> s1 >> s2;
    ll len1 = s1.size();
    ll len2 = s2.size();
    ll gd = gcd(len1, len2);
    ll len = len1*len2/gd;

    int i = 0,j = 0;
    ll sum = 0;
    for (int k = 0; k < len; ++k) {
      sum += (s1[i] == s2[j]?0:1);
      i = (i+1)%len1;
      j = (j+1)%len2;
    }
    cout << sum*len1*n/len << endl;
  }
  return 0;
}
