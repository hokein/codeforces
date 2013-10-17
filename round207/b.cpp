#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000000;

int a[N], b[N], c[N], n, m, color[N];

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m) {
    for (int i = 0; i < m; ++i)
      cin >> a[i] >> b[i] >> c[i];

    memset(color, 0, sizeof(color));
    color[a[0]] = 1;
    color[b[0]] = 2;
    color[c[0]] = 3;
    for (int i = 1; i < m; ++i) {
      vector<int> no_color_p;
      bool color_used[5] = {0};
      color_used[color[a[i]]] = 1;
      color_used[color[b[i]]] = 1;
      color_used[color[c[i]]] = 1;
      if (!color[a[i]]) {
        no_color_p.push_back(a[i]);
        //color_used[color[a[i]]] = 1;
      }
      if (!color[b[i]]) {
        no_color_p.push_back(b[i]);
        //color_used[color[b[i]]] = 1;
      }
      if (!color[c[i]]) {
        no_color_p.push_back(c[i]);
        //color_used[color[c[i]]] = 1;
      }
      for (int j = 0; j < no_color_p.size(); ++j) {
        for (int k = 1; k <= 3; ++k) {
          if (!color_used[k]) {
            color[no_color_p[j]] = k;
            color_used[k] = 1;
            break;
          }
        }
      }
    }

    for (int i = 1; i <= n; ++i) {
      if (i != 1)
        cout << " ";
      cout << color[i];
    }
    cout << endl;
  }
  return 0;
} 
