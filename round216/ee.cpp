#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;
const int kMax = 1000006;

bool cmp1(const P& p1, const P& p2) {
  return p1.second < p2.second;
}

struct Info {
  int st, ed, id;
  Info() {}
  Info(int st, int ed, int id) {
    this->st = st;
    this->ed = ed;
    this->id = id;
  }
};

bool cmp2(const Info& p1, const Info& p2) {
  return p1.ed < p2.ed;
}

int n, m, bit[kMax], ans[kMax];
P A[kMax];
vector<Info> info;

void add(int pos, int val) {
  while (pos < kMax) {
    bit[pos] += val;
    pos += ((pos)&(-pos));
  }
}

int query(int pos) {
  int res = 0;
  while (pos) {
    res += bit[pos];
    pos -= ((pos)&(-pos));
  }
  return res;
}
int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m) {
    memset(bit, 0, sizeof(bit));
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n; ++i)
      cin >> A[i].first >> A[i].second;
    info.clear();
    for (int i = 0; i < m; ++i) {
      int cnt;
      cin >> cnt;
      int p1, p2;
      cin >> p1;
      for (int j = 1; j < cnt; ++j) {
        cin >> p2;
        info.push_back(Info(p1, p2, i));
        p1 = p2;
      }
      info.push_back(Info(p1, kMax, i));
    }
    sort(A, A+n, cmp1);
    sort(info.begin(), info.end(), cmp2);

    int k = 0;
    for (int i = 0; i < info.size(); ++i) {
      while (k < n && A[k].second < info[i].ed) {
        add(A[k].second+1, -1);
        add(A[k].first, 1);
        ++k;
      }
      ans[info[i].id] += query(info[i].st);
    }
    for (int i = 0; i < m; ++i)
      cout << ans[i] << endl;
  }
  return 0;
} 
