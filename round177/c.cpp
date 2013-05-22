#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int MAX = 10000005;

int n, k, cnt;
char s[MAX];
int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> k) {
    if (k > n || (n > 1 && k == 1)) {
      cout << -1 << endl;
      continue;
    }

    cnt = 0;

    for (int i = 0; i < n-(k-2); ++i) {
      if (i%2 == 0)
        s[i] = 'a';
      else
        s[i] = 'b';
    }
    for (int i = n-(k-2); i < n; ++i) {
      s[i] = i-(n-(k-2))+'c';
    }
    s[n] = '\0';
    cout << s << endl;
  }
  return 0;
} 
