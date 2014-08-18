#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
using namespace std;


string nums[] = {
  "1111011",
  "1111111",
  "1110000",
  "1011111",
  "1011011",
  "0110011",
  "1111001",
  "1101101",
  "0110000",
  "1111110"
};

const int N = 1000;
string codes[N];
int n;
bool sure_broken[10], sure_good[10];

bool is_match(const string& stand, const string& code) {
  for (int i = 0; i < stand.size(); ++i) {
    if (sure_good[i] && sure_broken[i])
      return false;
    if (stand[i] == code[i]) {
      if (code[i] == '1' && sure_broken[i])
        return false;
    } else if (stand[i] == '1' && code[i] == '0') {
      if (sure_good[i])
        return false;
      sure_broken[i] = true;
    } else {
      return false;
    }
  }
  return true;
}

string generate_output(const string& s) {
  string ans = s;
  for (int i = 0; i < ans.size(); ++i) {
    if (ans[i] == '1' && sure_broken[i]) {
      ans[i] = '0';
    } 
    if (ans[i] == '1' && !sure_good[i])
      return "";
  }
  return ans;
}

int main() {
  //freopen("test.txt", "r", stdin);
  freopen("A-large-practice.in", "r", stdin);
  freopen("A-large-practice2.out", "w", stdout);

  int T, cases = 1;;
  cin >> T;
  while (T--) {
    cin >> n;
    string s;
    memset(sure_good, 0, sizeof(sure_good));
    for (int i = 0; i < n; ++i) {
      cin >> codes[i];
      for (int j = 0; j < codes[i].size(); ++j)
        if (codes[i][j] == '1')
          sure_good[j] = 1;
    }

    int times = 0;
    string ans;
    for (int i = 0; i < 10; ++i) {
      memset(sure_broken, 0, sizeof(sure_broken));
      bool is_ok = true;
      for (int j = 0; j < n && is_ok; ++j)
        is_ok &= is_match(nums[(j+i)%10], codes[j]);
      if (is_ok) {
        string tmp = generate_output(nums[(i+n)%10]);
        if (times == 0 || ans != tmp) {
          ++times;
        }
        if (times == 1)
          ans = tmp;
      }
    }
    
    cout << "Case #" << cases++ << ": ";
    if (times == 1 && !ans.empty()) 
      cout << ans << endl;
    else
      cout << "ERROR!" << endl;
  }
  return 0;
} 

