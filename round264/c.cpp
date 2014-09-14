#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
using namespace std;

typedef pair<int, int> P;

const int N = 2005;

long long maze[N][N], diagon1[N*2], diagon2[N*2];
int n;

inline long long sum(const P& p) {
  int i = p.first;
  int j = p.second;
  return diagon1[i+j] + diagon2[n-1-i+j] - maze[i][j];
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (scanf("%d", &n) != EOF) {
    memset(diagon1, 0, sizeof(diagon1));
    memset(diagon2, 0, sizeof(diagon2));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        scanf("%d", &maze[i][j]);
        diagon1[i+j] += maze[i][j];
        diagon2[n-1-i+j] += maze[i][j];
      }

    P p1(0, 0), p2(0, 1);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        if ((i+j)%2 == 0) {
          if (sum(p1) < sum(P(i, j))) {
            p1 = P(i, j);
          }
        } else {
          if (sum(p2) < sum(P(i, j))) {
            p2 = P(i, j);
          }
        }
      }
    cout << sum(p1) + sum(p2) << endl;
    cout << p1.first+1 << " " << p1.second+1 << " "
         << p2.first+1 << " " << p2.second+1 << endl;
  }
  return 0;
} 
