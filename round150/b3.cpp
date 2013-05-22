#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std; 

typedef long long ll;
const int N = 100;

ll n;
set<ll> s;
void dfs(int i, int j, ll cur_val) {
  if (cur_val > n)
    return;
  
  if (cur_val > 0)
    s.insert(cur_val);

  if (cur_val != 0 || i != 0)
    dfs(i, j, cur_val*10+i);
  if (cur_val != 0 || j != 0)
    dfs(i, j, cur_val*10+j);
}

int main() { 
  while (cin >> n) {
    for (int i = 0; i < 10; i++) 
      for (int j = i; j < 10; j++) 
        dfs(i, j, 0);

    cout << s.size() << endl;
  }

  return 0;
}
