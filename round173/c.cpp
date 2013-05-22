#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

bool is_all_zero(const string& s) {
  for (int i = 0; i < s.size(); ++i) 
    if (s[i] != '0')
      return false;
  return true;
}

bool is_one(const string& s) {
  return s.size() == 1 && s[0] == '1';
}

int main() {
  string s1, s2;

  while (cin >> s1 >> s2) {
    if (s1 == s2) {
      cout << "YES" << endl;
    }
    else {
      if (s1.size() != s2.size() || (is_all_zero(s1) && !is_all_zero(s2)) ||
          (is_all_zero(s2) && !is_all_zero(s1)) ||
          (is_one(s1) && !is_one(s2)) || 
          (is_one(s2) && !is_one(s1))) 
        cout << "NO" << endl;
      else 
        cout << "YES" << endl;
    }
  }
  return 0;
} 
