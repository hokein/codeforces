#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
using namespace std;

const int N = 300005;

int father[N], longest_path[N];
vector<int> v[N];
int n, m, q;
bool used[N];
int max_depth, max_pos;

void init() {
  for (int i = 1; i <= n; ++i) {
    v[i].clear();
    father[i] = i;
  }
}

int find_set(int a) {
  if (father[a] == a)
    return a;
  return father[a] = find_set(father[a]);
}
void union_set(int a, int b) {
  int id_a = find_set(a);
  int id_b = find_set(b);
  father[id_a] = id_b;
}

void dfs(int pos, int parent, int depth) {
  if (depth > max_depth) {
    max_depth = depth;
    max_pos = pos;
  }
  for (auto p: v[pos])
    if (p != parent)
      dfs(p, pos, depth+1);
}

int find_longest_path(int p) {
  max_depth = -1;
  dfs(p, -1, 0);
  max_depth = -1;
  dfs(max_pos, -1, 0);
  return max_depth;
}

int main() {
  freopen("test.txt", "r", stdin);

  while (cin >> n >> m >> q) {
    init();
    int a, b, c;
    for (int i = 0; i < m; ++i) {
      cin >> a >> b;
      v[a].push_back(b);
      v[b].push_back(a); 
      union_set(a, b);
    }

    memset(longest_path, 0, sizeof(longest_path));
    for (int i = 1; i <= n; ++i) {
      int region_id = find_set(i);
      if (!used[region_id]) {
        longest_path[region_id] = find_longest_path(i);
        used[region_id] = 1;
      }
    }

    for (int i = 0; i < q; ++i) {
      cin >> a >> b;
      if (a == 1) {
        int region_id = find_set(b);
        cout << longest_path[region_id] << endl;
      } else {
        cin >> c;
        int id1 = find_set(b);
        int id2 = find_set(c);
        if (id1 != id2) {
          father[id2] = id1;
          longest_path[id1] = max(longest_path[id1],
                                  max(longest_path[id2],
                                      (longest_path[id1]+1)/2 + (longest_path[id2]+1)/2 + 1));

        }
      }
    }
  }
  return 0;
} 
