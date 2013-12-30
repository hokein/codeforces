#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;

const int N = 505;

char maze[N][N];
int n, m, k;
bool vis[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int i, int j) {
  vis[i][j] = 1;

  for (int ii = 0; ii < 4; ++ii) {
    int x = i + dx[ii];
    int y = j + dy[ii];
    if (x >= 0 && x < n &&
        y >= 0 && y < m && maze[x][y] == '.' && !vis[x][y])
      dfs(x, y);
  }
  // reach end.
  if (k) {
    maze[i][j] = 'X';
    --k;
  }
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m >> k) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        cin >> maze[i][j];

    bool ok = false;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n && !ok; ++i)
      for (int j = 0; j < m && !ok; ++j)
        if (maze[i][j] == '.') {
          dfs(i, j);
          ok = 1;
          break;
        }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j)
        cout << maze[i][j];
      cout << endl;
    }
  }
  return 0;
} 
