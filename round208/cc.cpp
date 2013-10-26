#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;

const int N = 100010;
int a[N];

int main() {
  //freopen("test.txt", "r", stdin);

  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    int pos = 0;
    while (pos < n) {
      vector<P> v;
      bool meet_end = 0;
      for (int i = pos; a[i] != 0 && i < n; ++i) {
        v.push_back(P(a[i], i));
        if (i < n-1 && a[i+1] == 0)
          meet_end = 1;
      }

      sort(v.begin(), v.end());
      reverse(v.begin(), v.end());
      int max1, max2, max3;
      if (v.size() >= 3) {
        max1 = v[0].second;
        max2 = v[1].second;
        max3 = v[2].second;
        for (int& i = pos; a[i] != 0 && i < n; ++i) {
          if (i == max1) {
            cout << "pushStack" << endl;
          } else if (i == max2) {
            cout << "pushQueue" << endl;
          } else if (i == max3) {
            cout << "pushFront" << endl;
          } else {
            cout << "pushBack" << endl;
          }
        }
        if (meet_end)
          cout << 3 << " popStack popQueue popFront" << endl;
      }
      else if (v.size() == 2){
        max1 = v[0].second;
        max2 = v[1].second;
        for (int& i = pos; a[i] != 0 && i < n; ++i) {
          if (i == max1) {
            cout << "pushStack" << endl;
          } else if (i == max2) {
            cout << "pushQueue" << endl;
          } else {
            cout << "pushBack" << endl;
          }
        }
        if (meet_end)
          cout << 2 << " popStack popQueue" << endl;
      } else if (v.size() == 1) {
        max1 = v[0].second;
        for (int& i = pos; a[i] != 0 && i < n; ++i) {
          if (i == max1) {
            cout << "pushStack" << endl;
          } else {
            cout << "pushBack" << endl;
          }
        }
        if (meet_end)
          cout << 1 << " popStack" << endl;
      } else {
        cout << 0 << endl;
      }
      ++pos;
    }
  }
  return 0;
} 
