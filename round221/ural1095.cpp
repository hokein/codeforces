#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 10;

int times[N];
string s;

int main() {
  //freopen("test.txt", "r", stdin);

  //for (int i = 0; i < 1000; ++i) 
    //if (i%7 == 0)
      //cout << i << endl;
  //for (int reminder = 1; reminder < 10; ++reminder) {
    //int perm[] = {1,2,3,4};
    //do {
      //int value = 0;
      //for (int i = 0; i < 4; ++i)
        //value = 10*value + perm[i];
      //if ((reminder*10000+value)%7 == 0) {
        //cout << reminder << " " << value;
        //cout << endl;
        //break;
      //}
    //} while (next_permutation(perm, perm+4));
  //}

  int T;
  cin >> T;
  while (T--) {
    cin >> s;
    memset(times, 0, sizeof(times));
    for (int i = 0; i < s.size(); ++i)
      ++times[s[i]-'0'];
    --times[1];
    --times[2];
    --times[3];
    --times[4];

    int perm[] = {1, 2, 3, 4};
    int reminder = 0;
    vector<int> ans;
    for (int i = 1; i < 10; ++i)
      while (times[i]) {
        reminder = (reminder*10+i)%7;
        ans.push_back(i);
        --times[i];
      }

    do {
      int value = 0;
      for (int i = 0; i < 4; ++i)
        value = 10*value + perm[i];
      if ((reminder*10000+value)%7 == 0) {
        for (int i = 0; i < ans.size(); ++i)
          cout << ans[i];
        cout << value;
        while(times[0]--) {
          cout << 0;
        }
        cout << endl;
        break;
      }
    } while (next_permutation(perm, perm+4));
  }
  return 0;
} 

