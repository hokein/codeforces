#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;

const int INF = 100000000;
int n, m, a, b, i, j;

int my_abs(int s) {
  return s>0?s:-s;
}

int cal(int x, int y) {
  int dis1 = my_abs(i-x);
  int dis2 = my_abs(j-y);
  if (dis1%a != 0 || dis2%b != 0)
    return INF;
  int step1 = dis1/a;
  int step2 = dis2/b;
  if (step1 < step2) {
    int diff = step2 - step1;
    if (diff%2 == 0 && ((j-b>0 || j+b<=m)
                        && (i-a>0 || i+a <= n))) return step2;
  } else {
    int diff = step1 - step2;
    if (diff%2 == 0 && ((i-a>0 || i+a<=n)&&(j-b>0 || j+b<=m))) return step1;
  }
  return INF;
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m >> i >> j >> a >> b) {
    if (i == 1 && j == 1 || i == 1 && j == m
        || i == n && j == 1
        || i == n && j == m) {
      cout << 0 << endl;
      continue;
    }
    int ans = min(min(cal(1, 1), cal(1, m)), min(cal(n,1), cal(n, m)));

    if (ans == INF)
      cout << "Poor Inna and pony!" << endl;
    else
      cout << ans << endl;
  }
  return 0;
} 
