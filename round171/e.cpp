// dp[n][0]:前n个字母与目标字符符合，最小的需要的2^k数的数目
// dp[n][1]:前n个字母与目标字符完全相反，最小需要的2^k数的数目
//
// 注意到：dp[n][0]与dp[n][1]可以互相转化，通过两步即可：
//  1001 => 1111 - 1001 => 0110
//  1111 => 10000 - 1 => 2^4 - 2^0, 2 steps
//
// dp[i][0] = min(dp[i-1][0], dp[i-1][1]+2), s[i] = 0
//            min(dp[i-1][0]+1, dp[i-1][1]
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int INF = 100000000;
const int N = 1000005;

char s[N];
int dp[N][2];
int one_cnts[N];

int main() {
  while (cin >> (s+1)) {
    int len = strlen(s+1);
    dp[0][0] = 0;
    dp[0][1] = 2;
    for (int i = 1; i <= len; ++i) {
      if (s[i] == '0') {
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = min(dp[i-1][0]+2, dp[i-1][1]+1);
      }
      else {
        dp[i][0] = min(dp[i-1][0]+1, dp[i-1][1]);
        dp[i][1] = min(dp[i-1][1], dp[i-1][0]+2);
      }
      cout << dp[i][0] << " " << dp[i][1] << endl;
    }

    cout << min(dp[len][0],dp[len][1]) << endl;

   }
  return 0;
} 
