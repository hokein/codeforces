#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100000;

int n, s, t;
int d[N];

int main() {
  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      cin >> d[i+1];

    cin >> s >> t;

    if (t > s) 
      swap(t, s);

    int ans = 0;
    for (int i = t; i < s; ++i)
      ans += d[i];

    int part1 = 0, part2 = 0;
    for (int i = 1; i < t; ++i)
      part1 += d[i];
    for (int i = n; i >= s; --i)
      part2 += d[i];
    cout << min(ans, part1+part2) << endl;
  }
  return 0;
} 
