// Problem: given a sequence d0, d1, ..., dn, 0 <= d[i] <= 100
//          only can sum the pair (a,b) at least a == 0 or b == 0.
//          
//          find a maximal subset that any two numbers can sum.
//
// Solution: Note that the ans's range is [1, 4],  
//   1) select 0 or 100.
//   2) select one of number >0 and < 10
//   3) select one of number >=10 and < 100 and number%10 == 0        
//   4) if can not find a number of 2) and 3) , select a number >= 10 and < 100.
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000;

int data[N], n;

int main() {
  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      cin >> data[i];
    
    int ans = 0;
    bool vis[101] = {0};
    for (int i = 0; i < n; ++i)
      if (data[i] == 0 || data[i] == 100) {
        vis[data[i]] = 1;
        ans++;
      }

    bool only_one_dig = false;
    for (int i = 0; i < n; ++i) {
      if (data[i] > 0 && data[i] < 10) {
        only_one_dig = true;
        vis[data[i]] = 1;
        break;
      }
    }
    ans += only_one_dig;
    bool only_two_dig = false;
    for (int i = 0; i < n; ++i)
      if (data[i] >= 10 && data[i] < 100 && data[i]%10 == 0) {
        only_two_dig = true;
        vis[data[i]] = 1;
        break;
      }
        
    ans += only_two_dig;
    if (!only_one_dig && !only_two_dig)
      for (int i = 0; i < n; ++i)
        if (data[i] >= 10 && data[i] < 100 && data[i]%10 != 0) {
          vis[data[i]] = 1;
          ans++;
          break;
        }

    cout << ans << endl;
    for (int i = 0; i < 101; ++i)
      if (vis[i]) {
        cout << i;
        ans--;
        if (ans)
          cout << " ";
      }
    cout << endl;
  }
  return 0;
} 
