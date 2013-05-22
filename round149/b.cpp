#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std; 

const int N = 100005;
const int INF = 1000000009;
int l[N], r[N];
int n;

int main() { 
  while (cin >> n) {
    int l_min, r_max;
    l_min = INF;
    r_max = -1;
    for (int i = 0; i < n; i++) {
       cin >> l[i] >> r[i];
       l_min = l_min > l[i]? l[i]:l_min;
       r_max = r_max > r[i]? r_max:r[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
       if (l[i] == l_min && r[i] == r_max) {
          cout << i+1 << endl;
          ans++;
          break;
       }
    }

    if (ans == 0)
      cout << "-1" << endl;
  }
  return 0;
}
