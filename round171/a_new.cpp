#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int my_abs(int a) {
  return a > 0? a:-a;
}
int main() {
  //freopen("test.txt", "r", stdin);
  int x, y;

  while (cin >> x >> y) {
    if (x == 0 && y == 0)
      cout << 0 << endl;
    else if (x >= 0 && y > 0) {
      if (y <= x)
        cout << 1 + 4*(x-1) << endl;
      else
        cout << 2 + 4*(y-1) << endl;
    }
    else if (x < 0 && y >= 0) {
      x = my_abs(x);
      if (x <= y)
        cout << 2 + 4*(y-1) << endl;
      else
        cout << 3 + 4*(x-1) << endl;
    }
    else if (x <= 0 && y < 0) {
      x = my_abs(x);
      y = my_abs(y);
      if (y <= x)
        cout << 3 + 4*(x-1) << endl;
      else
        cout << 4 + 4*(y-1) << endl;
    }
    else if (x > 0 && y <= 0) {
      y = my_abs(y);
      if (x - y > 1)
        cout << 1 + 4*(x-1) << endl;
      else
        cout << 4 + 4*(y-1) << endl;
    }
  }

  return 0;
} 
