#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int MAX = 100005;

struct Node {
  int son;
};

Node nodes[MAX];
bool vis[MAX];
int n, s, t, v;

int dfs(int source) {
  vis[source] = 1;
  if (source == t)
    return 0;
  if (nodes[source].son != -1 && !vis[nodes[source].son]) {
    int tmp = dfs(nodes[source].son);
    if (tmp == -1) return -1;
    return tmp + 1;
  }
  return -1;
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> s >> t) {
    for (int i = 1; i <= n; ++i)
      nodes[i].son = -1;

    for (int i = 1; i <= n; ++i) {
      cin >> v;
      nodes[i].son = v; 
    }

    memset(vis, 0, sizeof(vis));
    int ans = dfs(s);
    cout << ans << endl;
  }
  return 0;
} 
