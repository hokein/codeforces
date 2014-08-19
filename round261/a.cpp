#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int x1, y1, x2, y2;
  //freopen("test.txt", "r", stdin);

  while (cin >> x1 >> y1 >> x2 >> y2) {
    if (x1 > x2) {
      swap(x1, x2);
      swap(y1, y2);
    }

    if (x1 == x2) {
      int len = abs(y2-y1);
      cout << x1+len << " " << y1 << " " << x2+len << " " << y2 << endl;
    } else if (y1 == y2) {
      int len = abs(x2-x1);
      cout << x1 << " " << y1+len << " " << x2 << " " << y2+len << endl;
    } else {
      int len1 = abs(y2-y1);
      int len2 = abs(x2-x1);
      if (len1 != len2) {
        cout << "-1" << endl;
        continue;
      }
      cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl;
    }

  }
  return 0;

}
