#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 10000;

int main() {
  //freopen("test.txt", "r", stdin);

  int n, m;
  while (cin >> n >> m) {
    bool is_evil[N] = {0};

    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b; 
      is_evil[a] = 1;
      is_evil[b] = 1;
    }
    int center = -1;
    for (int i = 1; i <= n; ++i)
      if (!is_evil[i]) {
        center = i;
        break;
      }
    cout << n-1 << endl;
    for (int i = 1; i <= n; ++i)
      if (i != center) {
        cout << center << " " << i << endl; 
      }
  }

  return 0;
} 
