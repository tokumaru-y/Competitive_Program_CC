#include <bits/stdc++.h>
using namespace std;
int main () {
    int a,b,c;
    scanf("%d %d %d", &a,&b,&c);
    if(a==b && b==c && c==a){
        printf("1");
    }else if(a!=b && b!=c && c!=a){
        printf("3");
    } else {
        printf("2");
    }
}