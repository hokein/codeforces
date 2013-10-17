// x...x(concatenate n x strings)
// y...y(concatenate m y strings)
// len1 = len(x), len2 = len(y);
// len1 * n = len2 * m;
// calcualte hamming distances of x...x and y...y
//
// gcd (len1, len2) = 1
// abcabcabcabc(abc * 4)
// wzyxwzyzwxyz(wxyz * 3)
// a => w, z, y, x
// b => w, x, y, z
// c => w, x, y, z   
//
// gcd (len1, len2) = 2
// xy xy xy xy
// abcd  abcd
// x => a, c, x对应s2以|gcd|长度划分的每个子串位置
// y => b, d
//
// 以lcm(len1, len2)为单位计算
// 统计每个字母在i%gcd位置上出现的次数，用lcm减去即可
// lcm就是s1，s2全部不同的hammming distance
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 2000000;
ll n, m;
string s1, s2;
int cnt[N][30];

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a%b);
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m) {
    cin >> s1 >> s2;
    ll len1 = s1.size();
    ll len2 = s2.size();
    ll gd = gcd(len1, len2);
    ll lcm = len1*len2/gd;

    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < len1; ++i)
      cnt[i%gd][s1[i]-'a']++;
    ll res = lcm;
    for (int i = 0; i < len2; ++i)
      res -= cnt[i%gd][s2[i]-'a'];
    cout << (n*gd)/len2*res << endl;
  }
  return 0;
} 

