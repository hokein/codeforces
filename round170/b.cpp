#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int N = 1000;

int n;
string s[N];
char a[N];

bool isvalid(int len) {
  a[len] = '\0';
  for (int i = 0; i < n; ++i)
    if (s[i].find(a) != s[i].npos)
      return false;

  return true;
}
void output(int len) {
  for (int i = 0; i < len; ++i)
    cout << a[i];
  cout << endl;
}

bool dfs(int dig_nums, int current_cnt) {
  if (current_cnt == dig_nums) {
    if (isvalid(current_cnt)) {
      output(current_cnt);
      return true;
    }
    return false; 
  }

  for (int i = 0; i < 26; ++i) {
    a[current_cnt] = 'a'+i;
    if (dfs(dig_nums, current_cnt+1))
      return true;
  }
  return false;
}

int main() {
  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      cin >> s[i];

    for (int i = 1; i < 21; ++i)
      if (dfs(i, 0))
        break;
  }
  return 0;
} 
