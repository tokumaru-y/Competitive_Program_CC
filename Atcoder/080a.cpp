#include <bits/stdc++.h>
using namespace std;
int main () {
    int n,a,b;
    scanf("%d %d %d", &n,&a,&b);
    int x = n * a;
    if (x<= b){
        printf("%d", x);
    } else {
        printf("%d", b);
    }
}