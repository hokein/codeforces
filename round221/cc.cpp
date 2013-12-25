// Find a permutation, which can be divided by 7. 
// Solution:
// 1) For every integer a(0~9), there exists a permutation of {1, 6, 8, 9}
// that is appended to a and makes the result number divisible by 7. 
// 2) For every integer a(0~9), there exists a permutation of {1, 2, 3, 4}
// that is appended to a and makes the result number divisible by 7. 
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
  // Test, enum all 0~9, to check to solution
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

  while (cin >> s) {
    memset(times, 0, sizeof(times));
    for (int i = 0; i < s.size(); ++i)
      ++times[s[i]-'0'];
    --times[1];
    --times[6];
    --times[8];
    --times[9];

    int perm[] = {1, 6, 8, 9};
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
