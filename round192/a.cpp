#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 100;
char maze[N][N];

int main() {
  //freopen("test.txt", "r", stdin);

  int r, c;

  while (cin >> r >> c) {
    int row_evil[N] = {0};
    int col_evil[N] = {0};
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j) {
        cin >> maze[i][j];
        if (maze[i][j] == 'S') {
          row_evil[i] = 1;
          col_evil[j] = 1;
        }
      }

    int ans = 0;
    bool vis[N][N] = {0};
    for (int i = 0; i < r; ++i) {
      if (row_evil[i])
        continue;
      for (int j = 0; j < c; ++j) {
        ans++;
        vis[i][j] = 1; 
      }
    }

    for (int i = 0; i < c; ++i) {
      if (col_evil[i])
        continue;
      for (int j = 0; j < r; ++j) {
        if (!vis[j][i])
          ans++;
        vis[j][i] = 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
} 
