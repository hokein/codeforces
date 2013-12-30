#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;

const int N = 505;

char maze[N][N];
int n, m, k;
bool vis[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Node {
  int x, y;
  int sum;
  Node() {}
  Node(int x, int y) { this->x = x; this->y = y; sum = 1; }
  vector<Node*> sons;
};

Node* dfs1(int i, int j) {
  vis[i][j] = 1;
  Node* node = new Node(i, j);
  for (int ii = 0; ii < 4; ii++) {
    int x = i+dx[ii];
    int y = j+dy[ii];
    if (x >= 0 && y >= 0 && x < n && y < m && maze[x][y] == '.'
        && !vis[x][y]) {
      (node->sons).push_back(dfs1(x, y));
      node->sum += ((node->sons).back())->sum;
    }
  } 
  return node;
}

void dfs_set(Node* node) {
  maze[node->x][node->y] = 'X'; 
  for (int i = 0; i < (node->sons).size(); ++i) {
    dfs_set((node->sons)[i]);
  }
  delete(node);
}

bool dfs2(Node* node, int steps) {
  if (steps == 0)
    return true;
  if (node->sum <= steps) {
    dfs_set(node);
  } else {
    for (int i = 0; i < (node->sons).size() && steps>0; ++i) {
      Node& son = *(node->sons)[i];
      if (son.sum >= steps) {
        dfs2(&son, steps);
        return true;
      } else {
        dfs_set(&son);
        steps -= son.sum;
      }
    }
  }
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m >> k) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        cin >> maze[i][j];

    bool ok = false;
    for (int i = 0; i < n && !ok; ++i)
      for (int j = 0; j < m && !ok; ++j)
        if (maze[i][j] == '.') {
          memset(vis, 0, sizeof(vis));
          Node* root = dfs1(i, j);
          dfs2(root, k);
          ok = 1;
        }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j)
        cout << maze[i][j];
      cout << endl;
    }
  }
  return 0;
} 

