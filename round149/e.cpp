//SegmentTree
//1. Query Operation:
//     Query sum of array[l]+..+array[r]
//2. Xor Operation: give x and range[l, r]
//     array[l]^x, ..., array[r]^x
//Make segment tree for each bit.
//The range of x is 10^6 <= 2^20, make 20 trees
//sum record the total numbers of the range bits 
//Xor operation to a range: 
//    calculate the complementary of the sum, 
//    sum[rt] = r-l+1 - sum[rt]
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std; 

typedef long long ll;
const int N = 100005;

ll data[N];
int n, m;

struct Segment {

  ll sum[N<<2];
  bool color[N<<2];
  
  void pushup(int rt) {
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
  }
  
  void build(int l, int r, int rt, int pos) {
    color[rt] = 0;
    if (l == r) {
      sum[rt] = (data[l]>>pos)&1;
      return;
    }
    
    int m = l + (r-l)/2;
    build(l, m, rt<<1, pos);
    build(m+1, r, rt<<1|1, pos);
    pushup(rt);
  }
  
  void pushdown(int l, int r, int rt) {
    if (color[rt]) {
      color[rt<<1] = !color[rt<<1];
      color[rt<<1|1] = !color[rt<<1|1];
      sum[rt] = r-l+1 - sum[rt];
      int m = l + (r-l)/2;
      sum[rt<<1] = m-l+1 - sum[rt<<1];
      sum[rt<<1|1] = r-(m+1)+1 - sum[rt<<1|1];
      color[rt] = 0;
    }
  }
  
  void update(int l, int r, int ul, int ur, int rt) {
    if (ul <= l && ur >= r) {
      color[rt] = !color[rt];
      sum[rt] = r-l+1 - sum[rt];
      return;
    }
  
    pushdown(l, r, rt);
    int m = l + (r-l)/2;
    if (ul <= m)
      update(l, m, ul, ur, rt<<1);
    if (ur > m)
      update(m+1, r, ul, ur, rt<<1|1);
    pushup(rt);
  }
  
  ll query(int l, int r, int ql, int qr, int rt) {
    if (ql <= l && qr >= r) {
      return sum[rt];
    }
    pushdown(l, r, rt);
    ll ans = 0;
    int m = l + (r-l)/2;
    if (ql <= m)
      ans += query(l, m, ql, qr, rt<<1);
    if (qr > m)
      ans += query(m+1, r, ql, qr, rt<<1|1);
    pushup(rt);
  
    return ans;
  }

};

Segment tree[20];

int main() 
{ 
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      cin >> data[i+1];
    }

    for (int j = 0; j < 20; ++j) {
      tree[j].build(1, n, 1, j);
    }

    cin >> m;
    int t, l, r;
    for (int i = 0; i < m; ++i) {
      cin >> t;
      if (t == 1) {
        cin >> l >> r;
        ll ans = 0;
        for (int j = 0; j < 20; ++j) 
          ans += tree[j].query(1, n, l, r, 1) << j;
        
        cout <<  ans << endl;
      }
      else {
        int x;
        cin >> l >> r >> x;

        for (int j = 0; j < 20; ++j) 
          if ((x>>j)&1) 
            tree[j].update(1, n, l, r, 1);
      }
    }
  }

  return 0;
}
