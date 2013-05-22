#include<cmath>
#include<cstdio>
#include<cctype>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define for1(i,a,b) for(i=(a);i<(b);i++)
#define for2(i,a,b) for(i=(a);i>(b);i--)
#define same(a) memset((a),0,sizeof(a));
#define ll long long

const int MOD = 1000000009;

int cmpint(const void*a,const void *b)
{
    if(((int*)a)[0]==((int*)b)[0])
      return ((int*)a)[1]-((int*)b)[1];
    return ((int*)a)[0]-((int*)b)[0];
}

int  a[100005];
char s[1000005];
int main()
{
    int i,j,n,m,k,l,o,p;
    scanf("%s",s);
    l=strlen(s);
    for2(i,l,0)
      s[i]=s[i-1];
    s[0]='0';
    l++;
    k=0;
    for2(i,l-1,0){
        if(s[i]=='0') continue;
        if(s[i-1]=='0') k++;
        else {
            k++;
            while(s[i]=='1')
                i--;
            s[i]='1';
            i++;
        }
    }
    if(s[0]=='1') k++;
    printf("%d\n",k);
    return 0;
}

