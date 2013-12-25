#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 105;

int num[N][N];
int value[N];
int n, m;

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m) {
    memset(value, 0, sizeof(value));
    int a, b, c;
    for (int i = 0; i < m; ++i) {
      cin >> a >> b >> c;
      value[a] += -c;
      value[b] += c;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
      if (value[i] > 0)
        ans += value[i];
    cout << ans << endl;
  }
  return 0;
} 
