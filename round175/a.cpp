#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int MAX = 100005;

int data[MAX];
int main() {
  //freopen("test.txt", "r", stdin);

  int n, k;

  while (cin >> n >> k) {
    for (int i = 0; i < k; ++i)
      data[i] = n-i;

    for (int i = k; i < n; ++i) {
      data[i] = i-k+1;
    }
    for (int i = 0; i < n-1; ++i) {
      cout << data[i] << " "; 
    }
    cout << data[n-1] << endl;
  }
  return 0;
} 
