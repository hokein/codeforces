// dp[0][n]: feed n-1, then feed [i, ..., n]
// dp[1][n]: feed [i, ..., n], then feed n-1;
//
// dp[0][i] = b[i]+dp[0][i+1], a[i]+dp[1][i+1]
// dp[1][i] = c[i]+dp[0][i+1], b[i]+dp[1][i+1]
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 3005;

int dp[2][N], a[N], b[N], c[N];

int main() {
  //freopen("test.txt", "r", stdin);

  int n;
  while (cin >> n) {
    for (int i = 1; i <= n; ++i)
      cin >> a[i];
    for (int j = 1; j <= n; ++j)
      cin >> b[j];
    for (int k = 1; k <= n; ++k)
      cin >> c[k];
    memset(dp, 0, sizeof(dp));
    dp[0][n] = a[n];
    dp[1][n] = b[n];
    // dp[0][i] = b[i]+dp[0][i+1], a[i]+dp[1][i+1]
    // dp[1][i] = c[i]+dp[0][i+1], b[i]+dp[1][i+1]
    for (int i = n-1; i > 0; --i) {
      dp[0][i] = max(b[i]+dp[0][i+1], a[i]+dp[1][i+1]);
      dp[1][i] = max(c[i]+dp[0][i+1], b[i]+dp[1][i+1]);
    }
    cout << dp[0][1] << endl;  

  }
  return 0;
} 
