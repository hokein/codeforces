#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
  //freopen("test.txt", "r", stdin);

  int a, b;
  while (cin >> a >> b) {
    int sum = 0;
    while (a >= b) {
      sum += b;
      a -= b;
      ++a;
    }
    cout << sum + a << endl;
  }
  return 0;
} 
