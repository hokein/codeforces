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

  int l[N];
int main() {
  freopen("test.txt", "r", stdin);

  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      cin >> num[i];

    int len = 0;
    for (int i = 0; i < n; ++i) {
      int pos = lower_bound(a, a+len, num[i]) - a;
      a[pos] = num[i];
      l[i] = pos+1;
      cout << l[i] << " ";
      if (pos == len)
        ++len;
    }
    cout << endl;
    cout << len << endl;
  }
  return 0;
} 

