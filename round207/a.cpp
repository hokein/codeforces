#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000;

int a[N], x, y, n;
int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
    }
    cin >> x >> y;
    int ans = 0, sum1 = 0;
    for (int i = 0; i < n; ++i) {
      sum1 += a[i];
      if (sum1 >= x && sum1 <= y && sum-sum1 >= x && sum-sum1 <= y) {
        ans = i+2;
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
} 
