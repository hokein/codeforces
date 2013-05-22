#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std; 

const int N = 10000000;
const int MOD = 1073741824;

int value[N];
bool is_prime[N];

void cal_prime(int n)
{
  is_prime[1] = 0;
  for (int i = 2; i <= n; i++)
    is_prime[i] = 1;

  for (int i = 2; i <= n; i++)
    if (is_prime[i])
    {
       for (int j = 2; i*j <= n; j++)
         is_prime[i*j] = 0;
    }
}
int inline count(int num)
{
  if (num == 1) return 1;

  int ans = 2;
  int sqrt_num = sqrt((double)num);

  for (int i = 2; i <= sqrt_num; i++)
    if (num%i == 0)
      ans += 2;
  
  if (sqrt_num*sqrt_num == num)
    ans--;
  return ans;
}

void preprocess(int a, int b, int c)
{
  int total = a*b*c;
  value[1] = 1;

  cal_prime(total);
  for (int i = 2; i <= total; i++)
  {
    if (is_prime[i]) 
      value[i] = 2;
    else
      value[i] = count(i);
  }
}

int main() 
{ 
	//freopen("test.txt", "r", stdin); 

  int a, b, c;

  while (cin >> a >> b >> c)
  {
    preprocess(a, b, c);
    long long ans = 0;
    for (int i = 1; i <= a; i++)
      for (int j = 1; j <= b; j++)
        for (int k = 1; k <= c; k++)
          ans = (ans+value[i*j*k])%MOD ;

    cout << ans << endl;
  }

  return 0;
}
