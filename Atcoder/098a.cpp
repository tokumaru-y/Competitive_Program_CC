#include <bits/stdc++.h>
using namespace std;

int main () {
    int a,b;
    scanf("%d %d", &a,&b);
    int x=a+b;
    int y=a-b;
    int z=a*b;
    int ans;
    if(x >=y && x>=z){
        ans = x;
    } else if (y>=x&&y>=z){
        ans=y;
    } else {
        ans =z;
    }
    printf("%d",ans);
}