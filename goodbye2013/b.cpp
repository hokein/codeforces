#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 10000;

int num[N];
int n;

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> num[i];
      sum += num[i];
    }

    int pos = 0;
    int left_pos = -1;
    int advance = 1;
    while (sum > 0) {
      if (pos + advance >= n)
        advance = -1;
      else if (pos + advance < 0)
        advance = 1;
      if (num[pos] > 0) {
        cout << "P";
        --num[pos];
        --sum;
        //if (pos + advance >= n)
          //advance = -1;
        //else if (pos + advance < 0)
          //advance = 1;
        //if (advance == 1)
          //cout << "R";
        //else
          //cout << "L";
        //pos += advance;
      }
      
      if (sum == 0) break;
      if (advance == 1)
        cout << "R";
      else
        cout << "L";
      pos += advance;
    }
    cout << endl;
    //while (sum > 0) {
      //if (num[pos] > 0) {
        //cout << "P";
        //--num[pos];
        //--sum;
        //if (num[pos] >= 0) {
          //if (left_pos == -1) {
            //left_pos = num[pos] == 0?-1:pos;
            //advance = 1;
            //pos += advance;
            //cout << "R";
          //} else {
            //if (left_pos == pos) {
              //if (num[left_pos] == 0)
                //left_pos = -1;
              //advance = 1;
              //pos += advance;
              //cout << "R";
            //} else {
              //advance = -1;
              //pos += advance;
              //cout << "L";
            //}
          //}
        //} else {
          //if (advance > 0)
            //cout << "R";
          //else
            //cout << "L";
          //pos += advance;
        //}
      //}
    //}
    
  }
  return 0;
} 
