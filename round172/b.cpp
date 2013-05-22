#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib> 
using namespace std;

typedef long long ll;
const int INF = 100001;

//check whether |a1/b1 - x/y| > |a2/b2 - x/y| 
bool isBig(ll a1, ll b1, ll a2, ll b2, ll x, ll y) {
  ll part1 = abs(a1*y-b1*x);
  ll part2 = abs(a2*y-b2*x);
  return (part1*b2*y) > (part2*b1*y) ;
}

int main() {
  //freopen("test.txt", "r", stdin);
  ll x, y, n;
  while (cin >> x >> y >> n) {
    int a=INF, b=1;
    for (int i = 1; i <= n; ++i) {
        ll low_bound = (x*i)/y;
        ll up_bound = low_bound+1;
        ll choose = low_bound;
        if (isBig(low_bound, i, up_bound, i, x, y)) 
          choose = up_bound;
        
        if (isBig(a, b, choose, i, x, y)) {
          a = choose;
          b = i;
        }
    }
    cout << a << "/" << b << endl;
  }
  return 0;
} 
