#include <iostream>
using namespace std;

const int N = 1005;
long long n, k, d;
int seq[N], times;
int students[N][N];

void dfs(int cnt) {
   if (times == n)
      return;
   if (cnt == d) {
     for (int i = 0; i < d; ++i)
       students[times][i] = seq[i];
     ++times;
     return;
  }
   for (int i = 1; i <= k && times < n; ++i) {
      seq[cnt] = i;
      dfs(cnt+1);
   }
}

int main() {
   //freopen("test.txt", "r", stdin);
   while (cin >> n >> k >> d) {
      bool is_valid = false;
      long long val = k;
      for (int i = 0; i < d && !is_valid; ++i) {
         is_valid = (val >= n);
         val *= k;
      }
      if (!is_valid) {
         cout << -1 << endl;
         continue;
      }
      times = 0;
      dfs(0);
      for (int i = 0; i < d; ++i) {
        for (int j = 0; j < n; ++j) {
          if (j != 0)
            cout << " ";
          cout << students[j][i];
        }
        cout << endl;
      }
   }
}
