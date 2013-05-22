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

int n;
int main() 
{ 
	//freopen("test.txt", "r", stdin); 

  while (cin >> n)
  {
    if (n == 1)
    {
      cout << "1" << endl;
      continue;
    }

    ull val = n*(n-1);

    ull num;
    ull ans = val;
    for (int i = n-2; i >= 1; i--)
    {
      num = (val*i)/gcd(val, i) ;
      ans = ans > num?ans:num;
    }
    cout << ans << endl;
      
  }


  return 0;
}
