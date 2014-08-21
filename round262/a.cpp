#include <iostream>
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m) {
     int stocks = n;
     int days = 1;
     while (stocks > 0) {
        if (days % m == 0)
           ++stocks;
        --stocks;
        if (stocks == 0)
          break;
        ++days;
     }
     cout << days << endl;
  }
}
