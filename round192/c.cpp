#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 105;
char maze[N][N];

int main() {
  //freopen("test.txt", "r", stdin);

  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        cin >> maze[i][j];

    int x[N], y[N];
    int size = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        if (maze[i][j] == '.') {
          x[size] = i;
          y[size++] = j;
          break;
        }
    }
    if (size == n) {
      for (int i = 0; i < size; ++i)
        cout << x[i]+1 << " " << y[i]+1 << endl;
    }
    else {
      size = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
          if (maze[j][i] == '.') {
            x[size] = j;
            y[size++] = i;
            break;
          }
      }
      if (size == n) {
        for (int i = 0; i < size; ++i)
          cout << x[i]+1 << " " << y[i]+1 << endl;;
      }
      else {
        cout << -1 << endl; 
      }
    }

  }

  return 0;
} 
