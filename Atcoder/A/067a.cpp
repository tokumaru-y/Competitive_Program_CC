#include <bits/stdc++.h>
using namespace std;
int main () {
    int a,b;
    scanf("%d %d",&a,&b);
    if(a%3 == 0 || b%3== 0 || (a+b)%3==0){
        printf("%s" ,"Possible");
    } else {
        printf("%s", "Impossible");
    }
}