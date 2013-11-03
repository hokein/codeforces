// construct the solution
// sort the array[1...2n]
// 1 2 3 4 .... 2n-1, 2n
// Obviously, sigma(1,i)|2i-2i-1| = n.
// swap(a[2i-1], a[2i]), minus 2. so swap k times.
// n - (n-2s) = 2k
// s = k, swap k times.
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 50005*10;

int a[N], n, k;

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> k) {
    for (int i = 1; i <= 2*n; ++i)
      a[i] = i;
    int swap_steps = k;
    int pos = 1;
    for (int i = 0; i < swap_steps; ++i) {
      swap(a[pos], a[pos+1]);
      pos+=2;
    }
    for (int i = 1; i <= 2*n; ++i) {
      cout << a[i];
      if (i != 2*n)
        cout << " ";
    }
    cout << endl;
  }

  return 0;
} 
