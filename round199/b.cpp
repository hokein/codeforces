#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const int N = 1000000;

struct Interval {
  int t, l, r;
};

int n, m, s, f;
Interval interval[N];

bool in_interval(int num, int i) {
  return num <= interval[i].r && num >= interval[i].l;
}

string do_append_operation(int ss, int ff) {
  if (ss < ff)
    return "R";
  return "L";
}

int move_s(int s, int f) {
  return s < f? s+1:s-1;
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m >> s >> f) {
    int t, l, r;
    for (int i = 0; i < m; ++i)
      cin >> interval[i].t >> interval[i].l >> interval[i].r;
     
    string path;
    int steps = 1, time_pos = 0;
    while (s != f) {
      int next_place = move_s(s, f);
      if (steps < interval[time_pos].t
          || (!in_interval(s, time_pos) && !in_interval(next_place, time_pos))) {
        path += do_append_operation(s, f);
        s = next_place;
      }
      else
        path += "X";
      if (steps == interval[time_pos].t)
        time_pos++;
      steps++;
    }
    cout << path << endl;
   }
  return 0;
} 
