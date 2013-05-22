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
    if (x == 0 && y == 0
        || x == 1 && y == 0)
      cout << 0 << endl;
    else if (x > 0 && x >= my_abs(y) && x - my_abs(y) != 1) 
      cout << 1 + 4*(x-1) << endl;
    else if (y > 0 && my_abs(x) <= y) 
      cout << 2 + 4*(y-1) << endl;
    else if (x < 0 && my_abs(x) >= my_abs(y)) 
      cout << 3 + 4*((my_abs(x))-1) << endl; 
    else if (y < 0 ) 
      cout << 4+4*(-y-1) << endl;
  }

  return 0;
} 
