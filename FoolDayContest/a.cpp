#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

string name[] = {
  "Washington",
  "Adams",
  "Jefferson",
  "Madison",
  "Monroe",
  "Adams",
  "Jackson",
  "Van Buren",
  "Harrison",
  "Tyler",
  "Polk",
  "Taylor",
  "Fillmore",
  "Pierce",
  "Buchanan",
  "Lincoln",
  "Johnson",
  "Grant",
  "Hayes",
  "Garfield",
  "Arthur",
  "Cleveland",
  "Harrison",
  "Cleveland",
  "McKinley",
  "Roosevelt",
  "Taft",
  "Wilson",
  "Harding",
  "Coolidge",
  "Hoover",
  "Roosevelt",
  "Truman",
  "Eisenhower",
  "Kennedy",
  "Johnson",
  "Nixon",
  "Ford",
  "Carter",
  "Reagan"
};

int main() {
  //freopen("test. txt", "r", stdin);
  int a;

  while (cin >> a) {
    cout << name[a-1] << endl;
  }

  return 0;
} 
