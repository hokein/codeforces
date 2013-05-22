#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std; 

typedef unsigned long long ull;

ull gcd(ull a, ull b)
{
  if (b == 0)
    return a;
  return gcd(b, a%b);
}

ull func(ull n)
{
  ull val = n*(n-1);

  ull num;
  ull ans = val;
  for (int i = n-2; i >= 1; i--)
  {
    num = (val*i)/gcd(val, i) ;
    ans = ans > num?ans:num;
  }
  return ans;
}

int main() 
{ 
  int n;
  while (cin >> n)
  {
    if (n == 1 || n == 2)
    {
      cout << n << endl;
      continue;
    }

    cout << max(func(n), func(n-1)) << endl;
  }

  return 0;
}

