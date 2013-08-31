#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int N = 1005;
typedef unsigned long long ull;
typedef long long ll;

bool isvalid[N][N];

int main() {
  //freopen("test.txt", "r", stdin);

  int n, m;

  while (cin >> n >> m) {
    bool invalid_row[N] = {0};
    bool invalid_col[N] = {1};
    int a, b;
    memset(isvalid, true, sizeof(isvalid));
    for (int i = 0; i < m; ++i) {
      cin >> a >> b;
      invalid_row[a] = true;
      invalid_col[b] = true;
      isvalid[a][b] = false;
    }
    int ans = 0;
    for (int i = 2; i <= n/2; ++i) {
      if (!invalid_row[i] && isvalid[i][1]) {
        ans++;
        if (isvalid[n][i] && !invalid_col[i])
          ans++;
        if (isvalid[n-i+1][n] && !invalid_row[n-i+1])
          ans++;
        if (isvalid[1][n-i+1] && !invalid_col[n-i+1])
          ans++;
      }
    }

    // middle line
    if (n%2 == 1) {
      if (!invalid_row[n/2+1] || !invalid_col[n/2+1]) 
        ans++;
    }

    cout << ans << endl;
  }
  return 0;
} 
