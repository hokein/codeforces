#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P; // num, index;

const int N = 1000000;

int a[N], n;
bool vis[N];
P sorted[N];
vector<P> records; // <l, r-l>

bool cmp(const P& p1, const P& p2) {
  if (p1.first != p2.first)
    return p1.first < p2.first;
  return p1.second < p2.second;
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sorted[i].first = a[i];
      sorted[i].second = i;
    }
    
    sort(sorted, sorted+n, cmp);
    memset(vis, 0, sizeof(vis));
    records.clear();
    int maxx = 0;
    for (int i = 0; i < n; ++i) {
      int num = sorted[i].first;
      int pos = sorted[i].second;
      if (!vis[pos]) {
        int prefix = pos, postfix = pos;
        while (prefix >= 0 && a[prefix]%num == 0) {
          vis[prefix] = 1;
          --prefix;
        }
        while (postfix < n && a[postfix]%num == 0) {
          vis[postfix] = 1;
          ++postfix;
        }
        records.push_back(P(prefix+1, (postfix-1)-(prefix+1)));
        maxx = max(maxx, (postfix-1)-(prefix+1));    
      }
    } 
    sort(records.begin(), records.end(), cmp);
    int cnt = 0;
    for (int i = 0; i < records.size(); ++i) {
      if (records[i].second == maxx)
        ++cnt;
    }
    cout << cnt << " " << maxx << endl;
    for (int i = 0; i < records.size(); ++i) {
      if (records[i].second == maxx) {
         --cnt;
         cout << records[i].first+1;
         if (cnt)
           cout << " ";
      }
    }
    cout << endl;
  }
  return 0;
} 
