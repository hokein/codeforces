#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int MAX = 10000;
int n, cnt;
struct Info {
  int w, t;
};

Info info[MAX];
bool isvalid(int sum) {
  int total = 0;

  int one_pos = -1; 
  int i;
  for (i = n-1; total >= sum && i >= 0; --i) {
    total += info[i].w;
    if (info[i].t == 1) {
      if (one_pos == -1)
        one_pos = i;
      else
        one_pos = info[one_pos].w < info[i].w? one_pos:i;
    }
  }
 
  if (total > sum && one_pos == -1)
    return false;

  for (int i = 0; i < (cnt-sum); ++i) {
    total += w[i];
  }
  return total <= sum;
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    int x, y;
    cnt = 0;
    for (int i = 0; i < n; ++i) {
      cin >> info[i].t >> info[i].w;
      cnt++;
      if (info[i].t == 2) 
        cnt++;
    }

    sort(w, w+n);

    int ans = cnt;
    int low = 1, high = cnt;
    while (low <= high) {
      int mid = low + (high-low)/2;
      if (isvalid(mid)) {
        ans = mid;
        high = mid-1;
      }
      else {
        low = mid+1;
      }
    }
    cout << ans << endl;
  }
  return 0;
} 
