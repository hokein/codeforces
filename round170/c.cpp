#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 200;
int n, m;
int lens[N], a[N][N];
bool vis[N], maze[N][N];

void dfs(int v) {
  vis[v] = 1;
  for (int i = 0; i < n; ++i) {
    if (!vis[i] && maze[v][i])
      dfs(i);
  }
}

bool is_connect(int u, int v) {
  for (int i = 0; i < lens[u]; ++i) {
    for (int j = 0; j < lens[v]; ++j)
      if (a[u][i] == a[v][j] && a[u][i] <= m && a[v][j] <= m)
        return true;
  }
  return false;
}

bool all_zero() {
  for (int i = 0; i < n; ++i)
    if (lens[i] != 0)
      return false;
  return true;
}

int main() {
  while (cin >> n >> m) {
    memset(maze, 0, sizeof(maze));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i) {
      cin >> lens[i];
      for (int j = 0; j < lens[i]; ++j)
        cin >> a[i][j];
    }

    for (int i = 0; i < n; ++i){
      for (int j = i+1; j < n; ++j) {
        if (is_connect(i,j)) {
          maze[i][j] = maze[j][i] = 1;
        }
      }
    }

    if (all_zero()) {
      cout << n << endl;
      continue;
    }

    dfs(0);
    int ans = 0;
    for (int i = 0; i < n; ++i) 
      if (!vis[i]) {
        ans++;
        dfs(i);
      }
    cout << ans << endl;
  }
  return 0;
} 
