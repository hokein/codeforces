#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
  //freopen("test.txt", "r", stdin);

  int r, h;
  while (cin >> r >> h) {
    int ans = h/r*2;
    int remain = h%r; 
    if (remain*1.0 >= sqrt(3.0)/2*r)
      ans += 3;
    else if (remain*1.0 >= r/2.0)
      ans += 2;
    else
      ans++;
    cout << ans << endl;
  }
  return 0;
} 
