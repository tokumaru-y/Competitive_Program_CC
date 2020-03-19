#include <bits/stdc++.h>
using namespace std;
int main () {
    int a,b;scanf("%d",&a);scanf("%d",&b);
    int ans=b-(a%b);
    if(a%b==0)ans=0;
    printf("%d\n",ans);
}