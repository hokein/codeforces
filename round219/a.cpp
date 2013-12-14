#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 10;

char maze[N][N];
int cnt[N];
int k;

int main() {
  //freopen("test.txt", "r", stdin);

  int size = 4;
  while (cin >> k) {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        cin >> maze[i][j];
        if (maze[i][j] >= '0' && maze[i][j] <= '9')
          cnt[maze[i][j]-'0']++;
      }
    }
    bool isvalid = true;
    for (int i = 1; i <= 9; ++i) {
      if (cnt[i] > 2*k) {
        isvalid = false;
        break;
      }
    }
    cout << (isvalid?"YES":"NO") << endl;
  }
  return 0;
} 
