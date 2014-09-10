#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
using namespace std;

const int N = 105;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
char maze[N][N];
int n;

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    getchar();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        cin >> maze[i][j];
      getchar();
    }

    bool ans = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int cnt = 0;
        for (int k = 0; k < 4; ++k) {
          int x = i+dx[k];
          int y = j+dy[k];
          if (x >= 0 && x < n &&
              y >= 0 && y < n)
            cnt += maze[x][y] == 'o';
        }
        ans &= cnt%2 == 0;
      }
    }
    cout << (ans?"YES":"NO") << endl;
  }
  return 0;
} 
