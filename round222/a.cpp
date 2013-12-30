#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int dis(int a, int b) {
  return a>b?a-b:b-a;
}
int main() {
  //freopen("test.txt", "r", stdin);

  int a, b, c;
  while (cin >> a >> b) {
    int cnt1, cnt2, cnt3;
    cnt1 = cnt2 = cnt3 = 0;
    for (int i = 1; i <= 6; ++i)
      if (dis(a, i) < dis(i, b))
        cnt1++;
      else if (dis(a, i) > dis(b, i))
        cnt3++;
      else
        cnt2++;
    cout << cnt1 << " " << cnt2 << " " << cnt3 << endl;
  }
  return 0;
} 
