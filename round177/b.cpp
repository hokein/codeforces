#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int MAX = 105;
const int INF = 1000000005;
int n, m, d;
int matrix[MAX][MAX];
int data[MAX*MAX];

int my_abs(int a) {
  return a > 0?a:-a;
}
int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m >> d) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> matrix[i][j];
        data[cnt++] = matrix[i][j];
      }
    }

    if (n == m && n == 1) {
      cout << "0" << endl;
      continue;
    }
    sort(data, data+cnt);
    bool has_solution = true;
    int sum = data[0];
    for (int i = 1; i < cnt; ++i) {
      if ((data[i]-data[i-1])%d != 0) {
         has_solution = false;
         break;
      }
      sum += data[i]; 
    }
    if (!has_solution) {
      cout << -1 << endl;
      continue;
    }
     
    //cout << (n*m*data[cnt/2]-sum)/d << endl;
    int k = data[cnt/2];
    int ans = 0;
    for (int i = 0; i < cnt; ++i) {
      ans += my_abs(data[i]-data[cnt/2])/d;
    }
    cout << ans << endl;
  }
  return 0;
} 
