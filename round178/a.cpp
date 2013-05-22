#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int MAX = 10000;

int size[MAX];
int n, m;

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      cin >> size[i+1];

    int x, y;
    cin >> m;
    for (int i = 0; i < m; ++i) {
      cin >> x >> y;
      if (x == 1) {
        size[x+1] += (size[x]-y);
        size[x] = 0;
      } else if (x == n) {
        size[x-1] += (y-1);
        size[x] = 0;
      } else {
        size[x-1] += (y-1); 
        size[x+1] += (size[x]-y);
        size[x] = 0;
      }
    }
    for (int i = 0; i < n; ++i)
      cout << size[i+1] << endl;
  }
  return 0;
} 
