#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 500000;

int l[N], r[N], x[N], ans[N], n, m;
bool vis[N];
set<int> nums;

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m) {
    nums.clear();
    for (int i = 1; i <= n; ++i) {
      nums.insert(i);
    }

    for (int i = 0; i < m; ++i)
      cin >> l[i] >> r[i] >> x[i];

    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < m; ++i) {
      set<int>::iterator it = nums.lower_bound(l[i]);
      vector<int> del;
      for (; it != nums.end() && *it <= r[i]; ++it) {
        if (*it != x[i]) {
          ans[*it] = x[i];
          del.push_back(*it);
        }
      }
      for (int j = 0; j < del.size(); ++j)
        nums.erase(del[j]);
    }

    for (int i = 1; i <= n; ++i) {
      if (i != 1)
        cout << " ";
      cout << ans[i];
    }
    cout << endl;
  }
  return 0;
} 
