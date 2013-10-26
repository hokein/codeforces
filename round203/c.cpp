#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000000;

typedef pair<int, int> P;

vector<P> p[N];
vector<string> steps;
int n;

bool cmp1(const P& a, const P& b) {
  if (a.first != b.first)
    return a.first < b.first;
  return a.second < b.second; 
}
bool cmp2(const P& a, const P& b) {
  if (a.first != b.first)
    return a.first > b.first;
  return a.second < b.second; 
}
bool cmp3(const P& a, const P& b) {
  if (a.first != b.first)
    return a.first > b.first;
  return a.second > b.second; 
}
bool cmp4(const P& a, const P& b) {
  if (a.first != b.first)
    return a.first < b.first;
  return a.second > b.second; 
}

void output_step(int x, char dir) {
  stringstream ss;
  ss << (x>0?x:-x);
  if (x != 0)
    steps.push_back("1 " + ss.str() + " " + string(1, dir));
}

void output_2() {
  steps.push_back("2");
}

void output_3() {
  steps.push_back("3");
}

void output(const P& dst, int type) {
  int x = dst.first;
  int y = dst.second;
  if (type == 0) {
    output_step(x, 'R');
    output_step(y, 'U');
    output_2();
    output_step(y, 'D');
    output_step(x, 'L');
    output_3();
  }
  else if (type == 1) {
    output_step(x, 'L');
    output_step(y, 'U');
    output_2();
    output_step(y, 'D');
    output_step(x, 'R');
    output_3();
  }
  else if (type == 2) {
    output_step(x, 'L');
    output_step(y, 'D');
    output_2();
    output_step(y, 'U');
    output_step(x, 'R');
    output_3();
  }
  else {
    output_step(x, 'R');
    output_step(y, 'D');
    output_2();
    output_step(y, 'U');
    output_step(x, 'L');
    output_3();
  }
}
int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    int x, y;
    for (int i = 0; i < 4; ++i)
      p[i].clear();
    for (int i = 0; i < n; ++i) {
      cin >> x >> y;
      if (x >= 0 && y >= 0)
        p[0].push_back(P(x, y));
      else if (x < 0 && y >= 0)
        p[1].push_back(P(x, y));
      else if (x <= 0 && y < 0)
        p[2].push_back(P(x, y));
      else
        p[3].push_back(P(x, y));
    }

    sort(p[0].begin(), p[0].end(), cmp1);
    sort(p[1].begin(), p[1].end(), cmp2);
    sort(p[2].begin(), p[2].end(), cmp3);
    sort(p[3].begin(), p[3].end(), cmp4);

    steps.clear();
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < p[i].size(); ++j) {
        output(p[i][j], i);
      }
    }

    cout << steps.size() << endl;
    for (int i = 0; i < steps.size(); ++i)
      cout << steps[i] << endl;
  }
  
  return 0;
} 
