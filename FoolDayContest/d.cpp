#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

char tolower(char c) {
  if (c >= 'A' && c <= 'Z')
    return c-'A'+'a';
  return c;
}
char toupper(char c) {
  if (c >= 'a' && c <= 'z')
    return c-'a'+'A';
  return c;
}
int main() {
  //freopen("test.txt", "r", stdin);

  //cout << (char)('a'+14) << endl;
  string s;
  int n;
  while (cin >> s) {
    cin >> n;
    //string ans = "";
    char ans[100];
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
      char c = tolower(s[i]);
      if (c < n+97) 
        ans[cnt++] = toupper(s[i]);
      else
        ans[cnt++] = tolower(s[i]);
    }
    ans[cnt++] = '\0';
    cout << ans << endl;
  }
  return 0;
} 
