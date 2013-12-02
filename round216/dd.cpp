#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;

const int N = 3005;

int n, k, p[N], cnt[N][N];
bool has_100_behind[N], all_zero_behind[N];

bool a_can_survice(int b) {
  return !has_100_behind[b];
}

bool a_can_die(int b) {
  return !all_zero_behind[b];
}

int bfs() {
  if (n == 1)
    return 1;
  queue<P> q;
  int ans = 1;
  q.push(P(0, 1));
  cnt[0][1] = 1;
  while (!q.empty()) {
    P ft = q.front();
    q.pop();
    int a = ft.first;
    int b = ft.second;
    if (a >= n || b >= n || cnt[a][b] > k)
      continue;
    if (a_can_survice(b) && p[a] > 0 && cnt[a][b+1] == 0) {
      ++ans;
      cnt[a][b+1] = cnt[a][b]+1;
      q.push(P(a, b+1));
    }
    if (a_can_die(b) && p[a] > 0 && cnt[b+1][b+2] == 0) {
      ++ans;
      cnt[b+1][b+2] = cnt[a][b]+1;
      q.push(P(b+1, b+2));
    }
    if (a_can_die(b) && p[a] >= 0 && p[a] < 100 && cnt[b][b+1] == 0) {
      ++ans;
      cnt[b][b+1] = cnt[a][b]+1;
      q.push(P(b, b+1));
    }
  }
  return ans;
}
int main() {
  while (cin >> n >> k) {
    for (int i = 0; i < n; ++i)
      cin >> p[i];
    has_100_behind[n] = false;
    all_zero_behind[n] = true;    
    for (int i = n-1; i >= 0; --i) {
      has_100_behind[i] = has_100_behind[i+1]||(p[i] == 100);
      all_zero_behind[i] = all_zero_behind[i+1]&&(p[i] == 0);
    }
    memset(cnt, 0, sizeof(cnt));
    cout << bfs() << endl;
  }
  return 0;
} 
