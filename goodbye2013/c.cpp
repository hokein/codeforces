#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P; // value, pos

const int N = 1000005;

int a[N], b[N], n;
P info[N];

bool cmp(const P& x, const P& y) {
  return x.first < y.first;
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      info[i] = P(a[i], i);
    }

    sort(info, info+n, cmp);
    int value = info[0].first;
    b[info[0].second] = value;
    for (int i = 1; i < n; ++i) {
      if (info[i].first > value) {
        b[info[i].second] = info[i].first;
        value = info[i].first;
      } else {
        ++value;
        b[info[i].second] = value;
      }
    }
    for (int i = 0; i < n-1; ++i)
      cout << b[i] << " ";
    cout << b[n-1] << endl;
  }
  return 0;
} 
