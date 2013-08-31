#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
  //freopen("test.txt", "r", stdin);

  int n;
  while (cin >> n) {
    int k = n / 2;
    int begin = 1, last = n*n;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < k; ++j) {
        cout << begin++ << " " << last--;  
        if (j != k-1)
          cout << " ";
      }
      cout << endl;
    }
  }
  return 0;
} 
