#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 100;

int maze[N][N], n, m;

bool is_one_cover() {
  return maze[1][1] == 1 || maze[n][m] == 1
         || maze[1][m] == 1 || maze[n][1] == 1;
}

bool is_two_cover() {
  for (int i = 1; i <= m; ++i)
    if (maze[1][i] == 1 || maze[n][i] == 1)
      return true;
  for (int j = 1; j <= n; ++j)
    if (maze[j][1] == 1 || maze[j][m] == 1)
      return true;
  return false;
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m) {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        cin >> maze[i][j];

    if (is_one_cover())
      cout << 1 << endl;
    else if (is_two_cover())
      cout << 2 << endl;
    else
      cout << 4 << endl;
  }

  return 0;
} 
