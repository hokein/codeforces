#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, char> P;
map<char, int> num2times;
int n, k;

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> k) {
    char c;
    getchar();
    num2times.clear();
    for (int i = 0; i < n; ++i) {
      cin >> c;
      ++num2times[c];
    }
    vector<int> times2num;
    for (auto& element: num2times) {
      times2num.push_back(element.second);
    }
    sort(times2num.begin(), times2num.end(), greater<int>());
    int sum = 0, i = 0;
    long long ans = 0;
    while (sum < k) {
      if (sum + times2num[i] <= k) {
        ans += (long long)times2num[i]*times2num[i];
        sum += times2num[i++];
      } else {
        ans += (long long)(k - sum)*(k-sum);
        break;
      }
    }
    cout << ans << endl;
  }

  return 0;
} 
