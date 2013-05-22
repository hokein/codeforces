#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int MAX = 1000000;

int l[MAX], r[MAX];
int n, k;

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> k) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> l[i] >> r[i];
      sum += (r[i]-l[i]+1);
    }

    if (sum%k == 0)
      cout << 0 << endl;
    else {
      int ans = (sum/k+1)*k-sum;
      //if (ans > sum-(sum/k)*k)
        //ans = sum-(sum/k)*k;
      cout << ans << endl;
    }
  }
  return 0;
} 
