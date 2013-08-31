// LIS: longest increasing sequence
// O(nlog(n)), using binary search.
// a[i] : 当前递增子序列长度为i的最末一个数的最小值
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000000;

int num[N], a[N];

int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      cin >> num[i];

    int len = 0;
    for (int i = 0; i < n; ++i) {
      int pos = lower_bound(a, a+len, num[i]) - a;
      a[pos] = num[i];
      if (pos == len)
        ++len;
    }
    cout << len << endl;
  }
  return 0;
} 
