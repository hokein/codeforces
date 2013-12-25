#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 5005;

char num[N][N];
int cnts[N][N], pos[N];
int n, m, col;
vector<int> buckets[N];

void counting_sort() {
  for (int i = 0; i < N; ++i) 
    buckets[i].clear();
  for (int i = 1; i <= n; ++i) {
    buckets[cnts[pos[i]][col]].push_back(pos[i]);
  }
  int pp = 1;
  for (int i = N-1; i >= 0; --i) {
    for (int j = 0; j < buckets[i].size(); ++j)
      pos[pp++] = buckets[i][j];
  }
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (scanf("%d%d", &n, &m) != EOF) {
    getchar();
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        num[i][j] = getchar();
      }
      getchar();
    }

    for (int i = 1; i <= n; ++i) {
      cnts[i][0] = 0;
      for (int j = 1; j <= m; ++j)
        if (num[i][j] == '1')
          cnts[i][j] = cnts[i][j-1] + 1;
        else
          cnts[i][j] = 0;
    }

    int ans = 0;
    for (int i = 1; i <= m; ++i) { // enum end col pos
      col = i;
      // sort row based on the number of 1s.
      for (int j = 1; j <= n; ++j)
        pos[j] = j;
      counting_sort();
      // Decrease sequence.
      int maxx = cnts[pos[1]][col];
      for (int j = 2; j <= n; ++j) {
        maxx = max(maxx, cnts[pos[j]][col]*j);
      }
      ans = max(ans, maxx);
    }
    printf("%d\n", ans);
  }
  return 0;
} 
