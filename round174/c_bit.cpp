#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int MAX = 200005;

ll tree[MAX+5];

ll lowbit(ll x) {
  return (x&((~x)+1));
}

void update(ll pos, ll value) {
  while (pos <= MAX) {
    tree[pos] += value;
    pos += lowbit(pos);
  }
}

ll query(int num) {
  ll sum = 0;
  while (num) {
    sum += tree[num];
    num -= lowbit(num);
  }
  return sum;
}

int main() {
  int n; 
  while (cin >> n) {
    memset(tree, 0, sizeof(tree));

    ll sum = 0;
    int len = 1, t;
    for (int i = 0; i < n; ++i) {
      cin >> t;
      switch (t) {
        case 1:
          ll a, x;
          cin >> a >> x;
          update(1, x);
          update(a+1, -x);
          sum += a*x;
          break;
        case 2:
          int k;
          cin >> k;
          ++len;
          update(len, k);
          update(len+1, -k);
          sum += k;
          break;
        case 3:
          ll tmp = query(len);
          sum -= tmp;
          update(len, -tmp);
          update(len+1, tmp);
          --len;
          break;
      }

      printf("%.6lf\n", sum*1.0/len);
    }
  }

  return 0;
} 
