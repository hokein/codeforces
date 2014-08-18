#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std;

const int N = 5005*2;

typedef pair<int, int> P;

map<string, int> ids;
vector<P> maze[N];
int n, m;

int insert(const string& s) {
  if (ids.find(s) == ids.end())
    ids[s] = ids.size();
  return ids[s];
}

void bfs(const string& s1, const string& s2) {
  if (ids.find(s1) == ids.end()
      || ids.find(s2) == ids.end())
    return ;
  int a = ids[s1];
  int b = ids[s2]; 
  queue<P> q;
  bool vis[N] = {0};
  for (auto p: maze[a]) {
    vis[p.first] = 1;
    q.push(P(p.first, p.second));
  }
  while (!q.empty()) {
    P tt = q.front(); // a->b
    q.pop();
    if (tt.first == b) {
      cout << s1 << "+" << s2 << "=" << tt.second << endl;
      return;
    }
    for (auto e: maze[tt.first]) // b->c
      for (auto ee: maze[e.first]) // c->d
        if (!vis[ee.first]) {
          vis[ee.first] = 1;
          q.push(P(ee.first, tt.second-e.second+ee.second));
        }
  }
}

int main() {
  //freopen("test.txt", "r", stdin);
  freopen("C-large-practice.in", "r", stdin);
  freopen("C-large-practice.out", "w", stdout);

  int T, cases = 1;
  cin >> T;
  while (T--) {
    cin >> n;
    ids.clear();
    for (int i = 0; i < N; ++i)
      maze[i].clear();
    for (int i = 0; i < n; ++i) {
      string line;
      cin >> line;
      for (int i = 0; i < line.size(); ++i)
        if (line[i] == '+' || line[i] == '=')
          line[i] = ' ';
      istringstream scin(line);
      string a, b;
      int v;
      scin >> a >> b >> v;
      int id_a = insert(a);
      int id_b = insert(b);
      maze[id_a].push_back(P(id_b, v));
      maze[id_b].push_back(P(id_a, v));
    }

    cin >> m;
    cout << "Case #" << cases++ << ": " << endl;
    for (int i = 0; i < m; ++i) {
      string line;
      cin >> line;
      for (int i = 0; i < line.size(); ++i)
        if (line[i] == '+')
          line[i] = ' ';
      string a, b;
      istringstream scin(line);
      scin >> a >> b;
      bfs(a, b);
    }
  }
  return 0;
} 
