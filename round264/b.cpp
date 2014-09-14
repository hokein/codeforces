#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
using namespace std;

const int N = 100005;

int height[N];
int n;

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    ++n;
    for (int i = 1; i < n; ++i)
      cin >> height[i];
    int cost = 0, sum = 0;
    for (int i = 1; i < n; ++i) {
      if (sum + height[i-1]-height[i] >= 0) {
        sum = sum + height[i-1]-height[i];
      } else {
        cost += -(sum+(height[i-1]-height[i]));
        sum = 0;
      }
    }
    cout << cost << endl;
  }
  return 0;
} 
