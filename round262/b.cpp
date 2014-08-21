#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long power(int a, int n) {
   long long ans = 1;
   for (int i = 0; i < n; ++i)
      ans *= a;
   return ans;
}

int dig_sum(long long val) {
   int cnt = 0;
   while (val) {
      cnt += val%10;
      val /= 10;
   }
   return cnt;
}

int main() {
   int a, b, c;
   //freopen("test.txt", "r", stdin);
   while (cin >> a >> b >> c) {
       int sums = 9*9;
       vector<long long> v;
       for (int i = 1; i <= sums; ++i) {
          long long val = power(i, a)*b + c;
          if (dig_sum(val) == i && val < 1e9) {
             v.push_back(val);
          }
       }
       sort(v.begin(), v.end());
       cout << v.size() << endl;
       for (int i = 0; i < v.size(); ++i) {
          if (i > 0) cout << " ";
          cout << v[i];
       }
       cout << endl;
   }
}
