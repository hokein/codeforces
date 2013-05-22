#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std; 

const int N = 100;
const int MOD = 1 << 30;

int cnt[N*N*N+10];

int main() 
{ 
  int total = N*N*N;
  for (int i = 1; i <= total; i++)
    for (int j = i; j <= total; j+=i)
      cnt[j]++;

  int a, b, c;
  cin >> a >> b >> c;

  int ans = 0;
  for (int i = 1; i <= a; i++)
    for (int j = 1; j <= b; j++)
      for (int k = 1; k <= c; k++)
        ans = (ans + cnt[i*j*k])%MOD; 

  cout << ans << endl;

  return 0;
}
