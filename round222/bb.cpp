#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 200000;

int a[N], b[N], n;

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      cin >> a[i] >> b[i];
    for (int i = 0; i < n/2; ++i)
      cout << 1;
    for (int i = n/2; i < n; ++i) {
      int pos = lower_bound(b, b+n, a[i])-b;
      if (i+pos+1 <= n)
        cout << 1;
      else
        cout << 0;
    }
    cout << endl;
    for (int i = 0; i < n/2; ++i)
      cout << 1;
    for (int i = n/2; i < n; ++i) {
      int pos = lower_bound(a, a+n, b[i])-a;
      if (i+pos+1 <= n)
        cout << 1;
      else
        cout << 0;
    }
    cout << endl;
  }
  return 0;
} 
