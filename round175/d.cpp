#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int MAX = 20;
const ll MOD = 1000000000+7;

int b[MAX];
bool vis[MAX], used[MAX];
int n;
ll ans, fact[MAX] ;

void dfs(int cur_pos) {
  if (cur_pos == n) {
    ++ans;
    ans %= MOD;
    return;
  }

  for (int i = 1; i <= n; ++i) {
    if (!used[i]) {
      used[i] = 1;
      b[cur_pos] = i;
      int tmp = (cur_pos+1+b[cur_pos]-2)%n;
      if (!vis[tmp]) {
        vis[tmp] = 1;
        dfs(cur_pos+1);
        vis[tmp] = 0;
      }
      used[i] = 0; 
    }
  }
}

// precalculate!
// int ans[] = {0, 1, 0, 18, 0, 1800, 0, 670320, 0, 734832000, 0, 890786230, 0, 695720788, 0, 150347555, 0};
int main() {
  fact[0] = 1;
  for (int i = 1; i <= 16; ++i)
    fact[i] = fact[i-1]*i;
  for (int i = 1; i <= 16; ++i)
    fact[i] %= MOD;
  
  while (cin >> n) {
    ans = 0;
    for (int i = 0; i < n; ++i)
      b[i] = i+1;
    memset(vis, 0, sizeof(vis));
    memset(used, 0, sizeof(used));
    
    dfs(0);
    cout << ((ans%MOD)*fact[n])%MOD << endl;
  }
  return 0;
} 
