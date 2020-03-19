#include <bits/stdc++.h>
using namespace std;
int main () {
    int a,b;
    scanf("%d %d", &a,&b);
    int s = a+b;
    int div=s/2;
    if (div*2 == s){
        printf("%d",div);
    } else {
        printf("%d", div+1);
    }
}