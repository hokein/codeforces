#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

string s;

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> s) {
    int pos;
    for (int i = 0; i < s.size(); ++i)
      if (s[i] == '^') {
        pos = i;
        break;
      }

    ll left_sum = 0;
    int len = 0; 
    for (int i = pos-1; i >= 0; --i) {
      ++len;
      if (s[i] == '=')
        continue; 
      else
        left_sum += (s[i]-'0')*len;
    }
    len = 0;
    ll right_sum = 0;
    for (int i = pos+1; i < s.size(); ++i) {
      ++len;
      if (s[i] == '=')
        continue;
      else
        right_sum += (s[i]-'0')*len;
    }
    if (left_sum > right_sum)
      cout << "left" << endl;
    else if (left_sum < right_sum)
      cout << "right" << endl;
    else 
      cout << "balance" << endl;
  }
  return 0;
} 
