#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
#include <algorithm>
using namespace std;

const int N = 1000000;

int data[N];
int n;

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> data[i];
      sum += data[i];
    }
    sort(data, data+n);
    int i = 0;
    long long ans = 0;
    while (1) {
      ans += sum;
      if (i + 1 == n) 
        break;
      ans += data[i];
      sum -= data[i++]; 
    }
    cout << ans << endl;
  }
  return 0;
} 
