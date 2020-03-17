#include <bits/stdc++.h>
using namespace std;
int main () {
    int a,b,c,d;
    scanf("%d",&a);scanf("%d",&b);scanf("%d",&c);scanf("%d",&d);
    int ans = a*c;
    if(a>b){
        ans += (d-c) * (a-b);
    }
    printf("%d",ans);
}