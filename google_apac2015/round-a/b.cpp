#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
using namespace std;

const int N = 105;

typedef pair<int, bool> P;
int maze[N][N];
int n;

// left or right
vector<int> merge1(vector<int>& nums) {
  vector<P> ret;
  for (int i = 0; i < nums.size(); ++i) {
    if (ret.empty())
      ret.push_back(P(nums[i], false));
    else {
      if (nums[i] == ret.back().first && !ret.back().second) {
        ret.back().first *= 2;
        ret.back().second = true;
      } else {
        ret.push_back(P(nums[i], false));
      }
    }
  }
  vector<int> ans;
  for (int i = 0; i < ret.size(); ++i)
    ans.push_back(ret[i].first);
  return ans;
}

int main() {
  freopen("test.txt", "r", stdin);
  //freopen("B-large.in", "r", stdin);
  //freopen("ans2.out", "w", stdout);

  int T, cases = 1;
  cin >> T;
  while (T--) {
    string dir;
    cin >> n >> dir;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        cin >> maze[i][j];

    if (dir == "left") {
      for (int i = 0; i < n; ++i) {
        vector<int> nums;
        for (int j = 0; j < n; ++j)
          if (maze[i][j] > 0)
            nums.push_back(maze[i][j]);
        vector<int> ret = merge1(nums);
        for (int j = 0; j < ret.size(); ++j)
          maze[i][j] = ret[j];
        for (int j = ret.size(); j < n; ++j)
          maze[i][j] = 0;
      }
    } else if (dir == "right") {
      for (int i = 0; i < n; ++i) {
        vector<int> nums;
        for (int j = n-1; j >=0; --j)
          if (maze[i][j] > 0)
            nums.push_back(maze[i][j]);
        vector<int> ret = merge1(nums);
        for (int j = 0; j < ret.size(); ++j)
          maze[i][n-j-1] = ret[j];
        for (int j = ret.size(); j < n; ++j)
          maze[i][n-1-j] = 0;
      }
    } else if (dir == "up") {
      for (int i = 0; i < n; ++i) {
        vector<int> nums;
        for (int j = 0; j < n; ++j)
          if (maze[j][i] > 0)
            nums.push_back(maze[j][i]);
        vector<int> ret = merge1(nums);
        for (int j = 0; j < ret.size(); ++j)
          maze[j][i] = ret[j];
        for (int j = ret.size(); j < n; ++j)
          maze[j][i] = 0;
      }
    } else {
      for (int i = 0; i < n; ++i) {
        vector<int> nums;
        for (int j = n-1; j >= 0; --j)
          if (maze[j][i] > 0)
            nums.push_back(maze[j][i]);
        vector<int> ret = merge1(nums);
        for (int j = 0; j < ret.size(); ++j)
          maze[n-1-j][i] = ret[j];
        for (int j = ret.size(); j < n; ++j)
          maze[n-1-j][i] = 0;
      }
    }
    cout << "Case #" << cases++ << ":" << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j > 0)
          cout << " "; 
        cout << maze[i][j];
      }
      cout << endl;
    }
  }

  return 0;
} 
