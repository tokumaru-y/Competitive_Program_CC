#include <bits/stdc++.h>
using namespace std;
int main () {
    int a,b;
    scanf("%d %d",&a,&b);
    if(a<=b) {
        printf("%d\n",(a+1)*b);
    }else {
        printf("%d\n",a*(b+1));
    }
}