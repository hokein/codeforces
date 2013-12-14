#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000000;

int n;
int nums[N], nums2[N];

int main() {
  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      cin >> nums[i];
    sort(nums, nums+n);

    for (int i = 0; i < n; ++i)
      nums2[i] = nums[i]*2;

    int cnt = 0, pos = n-1;
    for (int i = n/2-1; i >= 0; --i) {
      if (nums[pos] >= nums2[i]) {
        --pos;
        ++cnt;
      }
    }
    cout << n-cnt << endl;
  }
  return 0;
} 
