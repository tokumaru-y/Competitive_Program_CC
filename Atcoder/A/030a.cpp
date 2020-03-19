#include <bits/stdc++.h>
using namespace std;
int main () {
    float a,b,c,d;
    scanf("%f %f %f %f",&a,&b,&c,&d);
    float x=b/a;float y=d/c;
    if(x==y){
        printf("DRAW\n");
    } else if(x<y){
        printf("AOKI\n");
    } else {
        printf("TAKAHASHI\n");
    }
}