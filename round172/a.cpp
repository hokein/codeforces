#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main() {
  //freopen("test.txt", "r", stdin);

  string s;
  while (cin >> s) {
    if (s[0] >= 'a' && s[0] <= 'z') {
      s[0] = s[0] + 'A'-'a';
    }
    cout << s << endl;
  }
  return 0;
} 
