#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000005;

int n, a[N], cnt[N];

int solve() {
  int ans = 0;
  if (cnt[1] >= cnt[2]) { // 1 > 2
    cnt[1] -= cnt[2];
    cnt[3] += cnt[2];
    ans += cnt[2];
    // combine remain 1 to 3
    cnt[3] += cnt[1]/3;
    ans += cnt[1]/3*2;
    cnt[1] = cnt[1]%3;
    // enum all numbers 1 cases.
    if (cnt[1] > cnt[3]) {
      if (cnt[1] == 1) { // 1, 4
         if (cnt[3] >= 1) {
           ans++;
         } else if (cnt[4] >= 2) {  // move 1 of 4 to 1 to combine 3, 1 1s, 2 4s
           ans += 2;
         } else {
           return -1;
         }
      } else if (cnt[1] == 2) { // combine all 1 to 2s
        if (cnt[4] >= 1) {
          ans += 2;
        } else if (cnt[3] >= 2) {
          ans += 2;
        } else {
          return -1;
        }
      }
    } else { // cnt[1] <= cnt[3], combine 1 and 3 to 4.
      ans += cnt[1];
    }
  } else { // cnt[1] < cnt[2]
    ans += cnt[1];
    cnt[3] += cnt[1];
    cnt[2] -= cnt[1];
    // combine all 1s to 3.
    ans += cnt[2]/3*2;
    cnt[3] += cnt[2]/3*2;
    cnt[2] %= 3;
    // enum all numbers 2 cases.
    if (cnt[2] == 1) {
      if (cnt[4] >= 1) {
        ans++;
      } else if (cnt[3] >= 2){
        ans += 2;
      } else 
        return -1;
    } else if (cnt[2] == 2) {
      ans += 2;
    }
  }
  return ans;
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      cnt[a[i]]++;
    }
    cout << solve() << endl;
  }

  return 0;
} 
