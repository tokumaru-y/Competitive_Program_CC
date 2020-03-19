#include <bits/stdc++.h>
using namespace std;
int main () {
    int a,b,c;scanf("%d %d %d",&a,&b,&c);
    if(a<b){
        printf("%d",c/a);
    } else {
        printf("%d",c/b);
    }
}