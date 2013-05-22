#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000005;

ll data[N], match[N];
bool vis[N];
int n;

ll find(int num) {
  int bin[100], cnt = 0;
  int tmp = num, max_value = 0;
  while (num) {
    bin[cnt++] = num%2;
    num /= 2;
    max_value = max_value*2 + 1;
  }
  num = tmp;
  if (vis[max_value-num] == 1) {
    match[num] = 0;
    return 0;
  }
  vis[num] = vis[max_value-num] = 1;
  match[num] = max_value-num;
  match[max_value-num] = num;
  return max_value;
}
int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    memset(vis, 0, sizeof(vis));
    ll ans = 0;
    for (int i = n; i >= 0; --i) {
      if (!vis[i]) {
        ans += find(i);
      }
    }
    cout << ans*2 << endl;
    for (int i = 0; i < n; ++i) {
      cout << match[i] << " ";
    }
    cout << match[n] << endl;
  }

  return 0;
} 
