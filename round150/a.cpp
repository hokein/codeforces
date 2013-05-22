#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std; 

const int N = 100000;

int a[N];
int vis[N];

int main() { 
	//freopen("test.txt", "r", stdin); 
  int n, k;

  while (cin >> n >> k) {
  
    memset(vis, -1, sizeof(vis));
    for (int i = 0; i < k; i++) {
       cin >> a[i];
       vis[a[i]] = i+1;
    }

    int size = n*k;
    for (int i = 0; i < k; i++) {
      cout << a[i];
      int cnt = 1;
      if (cnt < n)
        cout << " ";
      for (int j = 1; j <= size; j++) {
        if (vis[j] == -1) {
          cout << j;
          cnt++;
          vis[j] = -2;
          if (cnt < n)
            cout << " ";
          else
            break;
        }
      }
      cout << endl;
    }


  }

  


  return 0;
}
