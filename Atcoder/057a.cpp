#include <bits/stdc++.h>
using namespace std;
int main () {
    int a,b;
    scanf("%d %d",&a,&b);
    if(a+b >= 24){
        printf("%d",a+b-24);
    } else {
        printf("%d", b+a);
    }
}