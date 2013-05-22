#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000;

int n, v1, v2;
vector<int> w1, w2;
int sum1[N], sum2[N];
int sz1, sz2;
int main() {
  //freopen("test.txt", "r", stdin);


  while (cin >> n) {
    int t, w;
    for (int i = 0; i < n; ++i) {
      cin >> t >> w;
      if (t == 1)
        w1.push_back(w);
      else
        w2.push_back(w);
    }

    sort(w1.begin(), w1.end());
    sort(w2.begin(), w2.end());

    sum1[0] = 0;
    sum2[0] = 0;
    for (int i = 1; i <= w1.size(); ++i)
      sum1[i] = sum1[i-1] + w1[i-1];
    for (int i = 1; i <= w2.size(); ++i)
      sum2[i] = sum2[i-1] + w2[i-1];

    v1 = w1.size();
    v2 = w2.size();
    int ans = v1+2*v2;
    for (int i = 0; i <= w1.size(); ++i) {
      for (int j = 0; j <= w2.size(); ++j) {
        if (sum1[v1-i]+sum2[v2-j] <= i+2*j)
          ans = min(i+2*j, ans);
      }
    }
    cout << ans << endl;
  }
  return 0;
} 
