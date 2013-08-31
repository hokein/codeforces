#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1005;

char maze[N][N];
bool vis[N][N];
int cnt[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
  //freopen("test.txt", "r", stdin);

  int r, c;

  while (cin >> r >> c) {
    int x, y;
    int p_x, p_y;
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j) {
        cin >> maze[i][j];
        if (maze[i][j] == 'E') {
          x = i;
          y = j;
        }
        if (maze[i][j] == 'S') {
          p_x = i;
          p_y = j;
        }
      }

    memset(cnt, 0, sizeof(cnt));

    queue<pair<int, int> > q;
    q.push(make_pair<int, int>(x, y));
    vis[x][y] = 0;
    cnt[x][y] = 0;
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    while (!q.empty()) {
      pair<int, int> ff = q.front();
      q.pop();
      x = ff.first;
      y = ff.second;
      for (int i = 0; i < 4; ++i) {
        int new_x = x+dx[i];
        int new_y = y+dy[i];
        if (new_x >= 0 && new_x < r && new_y >= 0 && new_y < c
            && maze[new_x][new_y] != 'T' && !vis[new_x][new_y]) {
          vis[new_x][new_y] = 1;
          cnt[new_x][new_y] = cnt[x][y]+1;
          q.push(make_pair<int, int>(new_x, new_y));
        }
      }
    }

    int sum = 0;
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
        if (maze[i][j] >= '0' && maze[i][j] <= '9' 
            && vis[i][j] && cnt[i][j] <= cnt[p_x][p_y]) {
          sum += maze[i][j]-'0';
        }
    cout << sum << endl;
  }
  return 0;
} 
