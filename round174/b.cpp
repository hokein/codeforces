#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000000;

char data[N];
int sum_i[N];

int main() {
  //freopen("test.txt", "r", stdin);

  int n;
  while (cin >> n) {
    cin >> (data+1);
    bool no_i = true;


    sum_i[0] = 0;
    for (int i = 1; i <= n && no_i; ++i) {
      sum_i[i] = sum_i[i-1];
      if (data[i] == 'I')
        sum_i[i]++;
    }

    int total = sum_i[n];
    int ans = 0;
    for (int i = 1; i <= n; ++i)
      if (data[i] != 'F') {
        if (sum_i[i-1]+sum_i[n]-sum_i[i] == 0)
          ans++;
      }
    cout << ans << endl;
  }
  return 0;
} 
