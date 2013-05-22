#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <queue>
using namespace std; 

const int N = 100005;

struct Point {
  int x, y;
  Point() {}
  Point(int x, int y){
    this->x = x;
    this->y = y;
  }
  int operator<(const Point& t)const {
    if (x != t.x)
      return x < t.x;
    else
      return y < t.y;
  }
};

struct Info {
  Point point;
  int steps;
};

int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

set<Point> vis;
set<Point> all;

Point rbegin, rend;

int n;

bool bfs()
{
   vis.clear();

   queue<Info> Q;
   Info info;
   info.point = rbegin;
   info.steps = 0;
   Q.push(info);

   while (!Q.empty()) {
     info = Q.front();
     Point cur = info.point;
     Q.pop();

     if (cur.x == rend.x && cur.y == rend.y) {
        cout << info.steps << endl;
        return true;
     }

     for (int i = 0; i < 8; i++) {
        int x = cur.x + dx[i];
        int y = cur.y + dy[i];
        Point new_p(x, y);
        if (all.find(new_p) != all.end()
            && vis.find(new_p) == vis.end()) {
           vis.insert(new_p);
           Info new_info;
           new_info.point = new_p;
           new_info.steps = info.steps+1;
           Q.push(new_info);
        }
     }
   }

   return false;
}

int main() 
{ 
  while (cin >> rbegin.x){
    cin >> rbegin.y;
    cin >> rend.x >> rend.y;
    cin >> n;

    int r, a, b;
    size = 0;
    for (int i = 0; i < n; i++) {
       cin >> r >> a >> b;
       for (int j = a; j <= b; j++)
          all.insert(Point(r, j));
    }

    if(!bfs())
       cout << -1 << endl;
  }

  return 0;
}
