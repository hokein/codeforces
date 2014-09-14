#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
using namespace std;

// dp[i][j] = dp[i-1][j-1] + 1, a[k][i] = a[k][j]
//            max(dp[i-1][j], dp[i][j-1])
//

const int N = 1005;
int n, k;
int pos[N][N];
bool maze[N][N], vis[N];
int permutations[10][N], len[N];

int dfs(int root) {
  if (len[root] != -1)
    return len[root];
  for (int i = 1; i <= n; ++i)
    if (maze[root][i]) {
      len[root] = max(len[root], dfs(i)+1);
    }
  len[root] = max(1, len[root]);
  return len[root];
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> k) {
    for (int i = 0; i < k; ++i)
      for (int j = 1; j <= n; ++j) {
        cin >> permutations[i][j];
        pos[i][permutations[i][j]] = j;
      }

    memset(maze, 0, sizeof(maze));
    for (int i = 1; i <= n; ++i) 
      for (int j = 1; j <= n; ++j) {
        if (i == j) continue;
        bool valid = 1;
        for (int z = 0; z < k && valid; ++z) {
          valid &= pos[z][i] < pos[z][j];
        }
        if (valid)
          maze[i][j] = 1;
      }

    int ans = 0;
    memset(len, -1, sizeof(len));
    for (int i = 1; i <= n; ++i)
      ans = max(ans, dfs(i));
    cout << ans << endl;
  }
  return 0;
} 
