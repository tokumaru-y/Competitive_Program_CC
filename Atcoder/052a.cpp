#include <bits/stdc++.h>
using namespace std;
int main () {
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int x=a*b;int y=c*d;
    if(x<=y){
        printf("%d",x);
    } else {
        printf("%d",y);
    }
}