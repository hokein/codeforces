#include <iostream>
#include <cstring>
using namespace std;

const int N = 100005;

int nums[N];
int tree[N*4+5], add[N*4+5];
int n, m, w, min_pos, mini;

void up(int rt) {
   tree[rt] = min(tree[rt*2]+add[rt*2], tree[rt*2 + 1]+add[rt*2 + 1]);
}

// [l, r)
void build_tree(int l, int r, int rt) {
   if (r - l == 1) {
      tree[rt] = nums[l];
      return;
   }
   int mid = l + (r-l)/2;
   build_tree(l, mid, rt*2);
   build_tree(mid, r, rt*2 + 1);
   up(rt);
}

void push_down(int rt) {
   add[rt*2] += add[rt];
   add[rt*2+1] += add[rt];
   add[rt] = 0;
}

// [ul, ur], [l, r)
void update_tree(int ul, int ur, int l, int r, int rt) {
    if (ul <= l && ur >= r) {
       add[rt] += 1;
       if (r - l == 1) {
         tree[rt] += add[rt];
         add[rt] = 0;
       }
       return;
    }
    push_down(rt);
    int mid = l + (r - l)/2;
    if (ur <= mid)
      update_tree(ul, ur, l, mid, rt*2);
    else if (ul >= mid)
      update_tree(ul, ur, mid, r, rt*2+1);
    else {
      update_tree(ul, mid, l, mid, rt*2);
      update_tree(mid, ur, mid, r, rt*2+1);
    }
    up(rt);
}

void query_min(int l, int r, int rt) {
   if (r - l == 1) {
     tree[rt] += add[rt];
     add[rt] = 0;
     if (tree[rt] == mini)
        min_pos = min(min_pos, l);
     return;
   }
   push_down(rt);
   int mid = l + (r-l)/2;
   if (tree[2*rt]+add[2*rt] <= tree[2*rt+1]+add[2*rt+1])
     query_min(l, mid, rt*2);
   else
     query_min(mid, r, rt*2+1);
   up(rt);
}

int main() {
  //freopen("test.txt", "r", stdin);
  while (cin >> n >> m >> w) {
    for (int i = 1; i <= n; ++i)
      cin >> nums[i];
    memset(add, 0, sizeof(add));
    build_tree(1, n+1, 1);
    for (int i = 0; i < m; ++i) {
      min_pos = n;
      mini = tree[1]+add[1];
      query_min(1, n+1, 1);
      update_tree(min_pos, min_pos+w, 1, n+1, 1);
    }
    cout << tree[1]+add[1] << endl;
  }
}
