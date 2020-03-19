#include <bits/stdc++.h>
using namespace std;
int main () {
    int a,b;
    scanf("%d %d",&a,&b);
    if(b-1>a-b){
        printf("%d",a-b);
    } else {
        printf("%d",b-1);
    }
}