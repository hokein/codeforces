#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 105;
int k, data[N], scc[N];
bool maze[N][N];

bool is_connet(int a, int b) {
  while (a && b) {
    if (a%10 != 0 && b%10 != 0)
      return false;
    a %= 10;
    b %= 10;
  }
  return true;
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> k) {
    memset(maze, 0, sizeof(maze));
    for (int i = 0; i < k; ++i) 
      cin >> data[i];

    for (int i = 0; i < N; ++i)
      maze[i][i] = 1;
    for (int i = 0; i < k; ++i)
      for (int j = i+1; j < k; ++j)
        maze[i][j] = maze[j][i] = is_connet(data[i], data[j]);

    int ans = -1;
    bool ans_vis[N] = {0};
    for (int i = 0; i < k; ++i) {
      queue<int> q;
      bool vis[N] = {0};
      q.push(i);
      vis[i] = 1;
      int cnt = 1;
      while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (int j = 0; j < k; ++j)
          if (!vis[j] && maze[j][f] && maze[f][j]) {
            bool is_valid = true;
            for (int s = 0; s < k && is_valid; s++)
              if (vis[s]) {
                is_valid = maze[s][j] && maze[j][s];
              }
            if (is_valid) {
              vis[j] = true;
              cnt++;
              q.push(j);
            }
          }
      }
     if (ans < cnt) {
       ans = cnt;
       memcpy(ans_vis, vis, sizeof(vis));
     }
    }
    cout << ans << endl;

    bool is_first = true;
    for (int i = 0; i < k; ++i)
      if (ans_vis[i]) {
        if (!is_first)
          cout << " ";
        cout << data[i];
        is_first = false;
      }
    cout << endl;

    //for (int s = 0; s < k; ++s)
      //for (int i = 0; i < k; ++i)
        //for (int j = 0; j < k; ++j)
          //maze[i][j] |= (maze[i][k]&maze[k][j]);

    //int scc_cnt = 0;
    //memset(scc, 0, sizeof(scc));
    //for (int i = 0; i < k; ++i) {
      //if (scc[i] == 0) {
        //scc[i] = ++scc_cnt;
        //for (int j = 0; j < k; ++j)
          //if (maze[i][j] && maze[j][i])
            //scc[j] = scc[i];
      //}
    //}

    //int cnt[N] = {0};
    //int maxx = -1, maxx_pos;
    //for (int i = 0; i < k; ++i) {
      //cnt[scc[i]]++;
      //if (maxx < cnt[scc[i]]) {
        //maxx = cnt[scc[i]];
        //maxx_pos = scc[i];
      //}
    //}

    //cout << maxx << endl;
    //bool is_first = true;
    //for (int i = 0; i < k; ++i)
      //if (scc[i] == maxx_pos) {
        //if (!is_first)
          //cout << " ";
        //cout << data[i];
        //is_first = false;
      //}
    //cout << endl;
  }
  return 0;
} 
