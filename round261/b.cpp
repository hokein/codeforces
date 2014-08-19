#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200005;
int beauty[N];


int main() {

  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i)
       cin >> beauty[i];
    sort(beauty, beauty+n);
    int min_count = 0, max_count = 0;
    for (int i = 0; i < n; ++i) {
       if (beauty[i] == beauty[0]) ++min_count;
       if (beauty[i] == beauty[n-1]) ++max_count;
    }

    if (beauty[0] == beauty[n-1])
      cout << "0 " << (long long)n*(n-1)/2 << endl;
    else
      cout << beauty[n-1]-beauty[0] << " " << (long long)min_count*max_count << endl;
  }  
  return 0;

}

