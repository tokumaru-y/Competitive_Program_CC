#include <bits/stdc++.h>
using namespace std;
int main () {
    int a,b;scanf("%d %d",&a,&b);
    int ans = b /a;
    if(b%a!=0)ans++;
    printf("%d",ans);
}