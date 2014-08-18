#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

const int N = 1000;

typedef pair<int, int> P;
int n, m, s[N];

void adjust(P& a) {
  if (a.first > a.second)
    swap(a.first, a.second);
}

int main() {
  //freopen("test.txt", "r", stdin);
  freopen("D-large-practice.in", "r", stdin);
  freopen("D-large-practice.out", "w", stdout);

  int T, cases = 1;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
      cin >> s[i];
    sort(s, s+n, greater<int>());
    multiset<P> boxes;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int len = 1 << s[i];
      auto it = boxes.lower_bound(P(len, len));
      if (it == boxes.end()) {
        ++ans;
        it = boxes.insert(P(m, m));
      }
      P p1, p2;
      p1.first = it->first;
      p1.second = it->second - len;
      p2.first = it->first-len;
      p2.second = len;
      adjust(p1);
      adjust(p2);
      boxes.erase(it);
      boxes.insert(p1);
      boxes.insert(p2);
    }
    cout << "Case #" << cases++ << ": " << ans << endl;
  }
  return 0;
} 
