#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100005;

int nums[N], n;
long long sums[N], cnt;
long long dp1[N], dp2[N];

int main() {
   //freopen("test.txt", "r", stdin);
   while (cin >> n) {
     
     for (int i = 1; i <= n; ++i)
      	cin >> nums[i];
     sort(nums+1, nums+n+1);
     int maxmium = nums[n];
     cnt = 1;
     memset(sums, 0, sizeof(sums));
     for (int i = 1; i <= n; ++i) 
       sums[nums[i]] += nums[i];
      
     dp1[0] = dp2[0] = 0;
     dp2[1] = sums[1];
     dp1[1] = sums[1];
     long long ans = 0;
     for (int i = 2; i <= maxmium; ++i) {
       dp1[i] = max(dp1[i-1], dp2[i-2]+sums[i]);
       dp2[i] = max(dp2[i-1], dp1[i]);
     }

     for (int i = 1; i <= maxmium; ++i)
        ans = max(ans, dp2[i]);
     cout << ans << endl;
   }
}

