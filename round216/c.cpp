#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P; // (pos, dis)

const int N = 100000;

vector<int> v[N];
bool is_broken[N];
set<P> is_road;
vector<int> ans;
int n;

bool dfs(int pos, int parent, bool has_road_path) {
  bool has_broken_children = false;
  for (int i = 0; i < v[pos].size(); ++i) {
    int next_pos = v[pos][i];
    if (next_pos != parent) {
      is_broken[next_pos] = false;
      if (is_road.find(P(pos, next_pos)) != is_road.end()) {
        has_broken_children = true;
        is_broken[next_pos] = true;
        dfs(next_pos, pos, true);
        has_road_path = false;
      } else {
        if (has_road_path) {
          has_broken_children |= dfs(next_pos, pos, true);
        } else {
          has_broken_children |= dfs(next_pos, pos, false);
        }
        if (has_broken_children)
          has_road_path = false;
      }
    }
  }
  if (!has_broken_children && has_road_path && is_broken[pos]) {
    ans.push_back(pos);
  }
  return has_broken_children;
}
int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    ans.clear();
    is_road.clear();
    for (int i = 0; i <= n; ++i)
      v[i].clear();
    memset(is_broken, 0, sizeof(is_broken));
    int a, b, c;
    for (int i = 1; i < n; ++i) {
      cin >> a >> b >> c;
      v[a].push_back(b);
      v[b].push_back(a);
      if (c == 2) {
        is_road.insert(P(a, b));
        is_road.insert(P(b, a));
      }
    }
    dfs(1, 0, false);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
      if (i != 0)
        cout << " ";
      cout << ans[i];
    }
    cout << endl;

  }
  return 0;
} 
