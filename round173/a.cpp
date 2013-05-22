#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
  //freopen("test.txt", "r", stdin);

  string s;
  int n;

  while (cin >> n) {
    int x = 0;
    for (int i = 0; i < n; ++i) {
      cin >> s;
      if (s[0] == 'X') {
        if (s[1] == '+')
          x++;
        else
          x--;
      }  
      else if (s[1] == '+') {
        x++;
      }
      else {
        x--;
      }
    }
    cout << x << endl;
  }
  return 0;
} 
