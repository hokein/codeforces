#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

const int INF = 100000000;
double my_abs(double a) {
  return a > 0? a:-a;
}


int main() {
  //freopen("test.txt", "r", stdin);

  ll x, y, n;

  while (cin >> x >> y >> n) {

      double res = x/(double)y;
      
      ll a=INF, b=1;
      for (int i = 1; i <= n; ++i) {
          ll low_bound = (x*i)/y;
          ll up_bound = low_bound+1;
          ll choose = low_bound;
          if (my_abs(up_bound/(double)i - res) < my_abs(low_bound/(double)i - res)) {
            choose = up_bound;
          }
          
          if (my_abs(a/(double)b - res) > my_abs(choose/(double)i - res)) {
            a = choose;
            b = i;
          }
        }
      
      cout << a << "/" << b << endl;
    }
  return 0;
} 

