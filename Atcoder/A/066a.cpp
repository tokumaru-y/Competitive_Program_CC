#include <bits/stdc++.h>
using namespace std;
int main () {
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int x=a+b;int y=b+c;int z=c+a;
    if(x <= y && x <= z) {
        printf("%d",x);
    } else if (y <=x && y <= z){
        printf("%d" , y);
    } else {
        printf("%d", z);
    }
}