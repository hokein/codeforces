#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std; 

const int N = 100;

int cnt[N];

int main() 
{ 
	//freopen("test.txt", "r", stdin); 

  string s;
  while (cin >> s)
  {
     memset(cnt, 0, sizeof(cnt));
     for (int i = 0; i < s.length(); i++)
       cnt[s[i]-'a']++;

     int ans = 0;
     for (int i = 0; i < 26; i++)
       if (cnt[i])
         ans++;

     if (ans%2 == 0)
       cout << "CHAT WITH HER!" << endl;
     else
       cout << "IGNORE HIM!" << endl;
  }

  return 0;
}
