#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std; 

int main() { 
  int x, y, a, b;

  while (cin >> x >> y >> a >> b) {
    int ans = 0;

    for (int i = max(b+1, a); i <= x; i++)
      for (int j = b; j < min(i, y+1); j++)
          ans++;
    cout << ans << endl;

    for (int i = max(b+1, a); i <= x; i++)
      for (int j = b; j < min(i, y+1); j++)
         cout << i << " " << j << endl;
  }


  return 0;
}
