#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std; 

typedef long long ll;
const int N = 100;

ll n, ans;
bool vis[10];

ll cal_mini(ll val, int len) {
  ll mini = 0;
  for (int t = 0; t < len; t++)
    mini = mini*10 + val;
  return mini;
}

bool has_two_nums(ll val) {
  memset(vis, 0, sizeof(vis));
  int cnt = 0;
  while (val) {
    if (!vis[val%10]) {
      vis[val%10] = 1;
      cnt++;
    }
    val /= 10;
  }
  return cnt == 2;
}

void dfs(int i, int j, int cur_pos, ll cur_val, int len) {
  if (has_two_nums(cur_val) && cur_val <= n && cur_val != 0) {
    ans++;
  }
  if (cur_pos >= len) {
    return;
  }

  dfs(i, j, cur_pos+1, cur_val*10+i, len);
  dfs(i, j, cur_pos+1, cur_val*10+j, len);
}

int main() { 
  while (cin >> n) {
    int tmp = n;
    int len = 0;
    while (tmp) {
      len++;
      tmp /= 10;
    }

    ans = 0;

    for (int k = 1; k <= len; k++)
      for (int i = 1; i < 10; i++)
        if (cal_mini(i, k) <= n)
          ans++;

    for (int i = 0; i < 10; i++) {
      if (i == 0) {
        for (int j = i+1; j < 10; j++) {
          dfs(i, j, 1, j, len);
        }
        continue;
      }
      for (int j = i+1; j < 10; j++) {
        dfs(i, j, 0, 0, len);
      }
    }

    cout << ans << endl;
  }

  return 0;
}
