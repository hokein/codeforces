//Reference:
//When you go from position i-1 into position i, 
//you should replace m = {m1,m2,..,mt} by m'={ai,m1|ai,m2|ai,...,mt|ai}.
//After that you should remove from m repeated values (if you use set, 
//set will do this dirty work itself). Then you should mark all numbers 
//from m in some global array (or put them into some global set). 
//At the end you should calculate answer from the global array (or set)
//
//Each iteration set m = {m1, m2,...,mt} is 20, because there are 20bits.
//algorithm complex: O(N*20)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std; 

const int N = 1<<21;

bool vis[N];
int n, a[N];

int main() { 
	//freopen("test.txt", "r", stdin); 

  while (cin >> n) {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      vis[a[i]] = 1;
    }

    set<int> s;
    s.insert(a[0]);
    for (int i = 0; i < n; ++i) {
      set<int> s2;
      s2.insert(a[i]);
      //maintain {ai, ai|m1, ai|m2, ..., ai|mt}
      //max size is 20
      for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        s2.insert(*it|a[i]);
        vis[*it|a[i]] = 1;
      }
      s = s2;
    }

    int ans = 0;
    for (int i = 0; i < N; ++i)
      ans += vis[i];
    cout << ans << endl;
  }

  return 0;
}
