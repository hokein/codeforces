#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int kMax = 10000;

int a[kMax], n, k, l, r, sn, sk;

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> k >> l >> r >> sn >> sk) {
    for (int i = 0; i < n; ++i)
      a[i] = l;
    int diff_k = sk-k*l;
    int each_k = diff_k/k;
    for (int i = 0; i < k; ++i) {
      a[i] += each_k;
    }
    for (int i = 0; i < diff_k%k; ++i)
      ++a[i];
    if (n != k) {
      int diff_n = (sn-sk)-(n-k)*l;
      int each_n = diff_n/(n-k);
      for (int i = k; i < n; ++i)
        a[i] += each_n;
      for (int i = k; i < k+diff_n%(n-k); ++i)
        ++a[i];
    }
    for (int i = 0; i < n; ++i) {
      if (i != 0)
        cout << " ";
      cout << a[i];
    }
    cout << endl;
  }
  return 0;
} 
