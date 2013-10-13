#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 10000000;
int num[N];
struct Info {
  int a, b, c;
  Info(int aa, int bb, int cc) { a = aa; b = bb; c = cc;}
};
int main() {
  //freopen("test.txt", "r", stdin);
  int n;
  while (cin >> n) {
    int cnt[10] = {0};
    for (int i = 0; i < n; ++i) {
      cin >> num[i];
      cnt[num[i]]++;
    }
    vector<Info> v;
    for (int i = 0; i < cnt[4]; ++i) {
      if (cnt[2]-- > 0)
        v.push_back(Info(1, 2, 4));
    } 
    if (v.size() == cnt[4]) {
      for (int i = 0; i < cnt[2]; ++i)
        if (cnt[6]-- > 0)
          v.push_back(Info(1, 2, 6));
      for (int i = 0; i < cnt[3]; ++i)
        if (cnt[6]-- > 0)
          v.push_back(Info(1, 3, 6));
    }
    if (cnt[1] == n/3 && v.size() == n/3) {
      for (int i = 0; i < v.size(); ++i)
        cout << v[i].a << " " << v[i].b << " " << v[i].c << endl;
    }
    else {
      cout << -1 << endl;
    }
  }
  return 0;
} 
