#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std; 

const int N = 100005;

int n, m;

vector<int> v[N];
bool vis[N];
int data[N];
int val[N];

int main() { 

  int u0, v0;
  while (cin >> n >> m) {
    
    for (int i = 0; i < n; i++)
      v[i].clear();

    for (int i = 0; i < m; ++i) {
      cin >> u0 >> v0;
      v[u0-1].push_back(v0-1);
      v[v0-1].push_back(u0-1);
    }
    
    queue<int> Q;
    for (int i = 0; i < n; i++) {
      cin >> data[i];
      if (data[i] == 0)
        Q.push(i);
    }

    if (Q.empty()) {
      cout << 0 << endl;
      continue;
    }
      
    memset(val, 0, sizeof(val));
    int ans[N];
    int len = 0;
    while (!Q.empty()) {
      int cur = Q.front();
      vis[cur] = 1;
      val[cur] += 1;
      ans[len++] = cur;
      Q.pop();

      for (int i = 0; i < v[cur].size(); i++) {
        int adj = v[cur][i];
        if (!vis[adj]) {
          val[ adj ]++;
          if (val[adj] == data[adj])
            Q.push(adj);
        }
      }
    }

    int i;
    for (i = 0; i < n; i++)
      if (val[i] == data[i]) {
        cout << -1 << endl;
        break;
      }

    if (i >= n) {
      cout << len << endl;
      for (int j = 0; j < len-1; j++)
          cout << ans[j]+1 << " ";
      cout << ans[len-1]+1 << endl;
    }

  }
  return 0;
}
