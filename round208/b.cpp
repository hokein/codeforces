#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
  //freopen("test.txt", "r", stdin);

  int n;
  while (cin >> n) {
    string s, sum="";
    string in;
    for (int i = 0; i < n; ++i) {
      cin >> s;
      sum += "<3" + s;
    }
    sum += "<3";
    cin >> in;
    int j = 0;
    for (int i = 0; i < in.size() && j < sum.size(); ++i) {
      if (in[i] == sum[j])
        ++j;
    }
    if (j == sum.size())
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
} 
