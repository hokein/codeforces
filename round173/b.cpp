#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000005;

struct Info {
  int id;
  int value;
};

int n;
Info info[N];
int sum[N], rsum[N];
char ans[N];

int cmp(const Info& a, const Info& b) {
  if (a.value == b.value)
    return a.id < b.id;
  return a.value < b.value;
}

int main() {
  int tmp;
  while (cin >> n) {
    for (int i = 0; i < n; ++i)
    {
      info[i].id = i;
      cin >> info[i].value >> tmp;
    }

    sort(info, info+n, cmp);

    sum[0] = 0;
    rsum[0] = 0;
    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i-1]+info[i-1].value;
      rsum[i] = rsum[i-1]+1000-info[i-1].value;
    }
    
    bool find_ans = false;
    for (int i = 1; i <= n && !find_ans; ++i) {
      if (abs(sum[i]-(rsum[n]-rsum[i])) <= 500) {
        find_ans = true;
        for (int j = 0; j < i; ++j) {
          ans[info[j].id] = 'A';
        }
        for (int j = i; j < n; ++j) {
          ans[info[j].id] = 'G';
        }
      }
      else if (abs((sum[n]-sum[i])-rsum[i]) <= 500) {
        find_ans = true;
        for (int j = 0; j < i; ++j) {
          ans[info[j].id] = 'G';
        }
        for (int j = i; j < n; ++j) {
          ans[info[j].id] = 'A';
        }
      }
    }

    if (!find_ans) {
      cout << "-1" << endl;
      continue;
    }

    for (int i = 0; i < n; ++i) {
      cout << ans[i];
    }
    cout << endl;
  }
  return 0;
} 
