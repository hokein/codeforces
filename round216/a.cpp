#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int kMax = 1000;

int num[kMax];

int main() {
  //freopen("test.txt", "r", stdin);

  int n, m, k;
  while (cin >> n >> m >> k) {
    for (int i = 0; i < n; ++i)
      cin >> num[i];

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (num[i] == 1) {
        if (m <= 0) {
          ++ans;
        } else {
          --m;
        }
      } else { // 2
        if (k <= 0) {
          if (m <= 0) {
            ++ans;
          } else {
            --m;
          }
        } else { 
          --k;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
} 
