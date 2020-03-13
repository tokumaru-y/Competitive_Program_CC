#include <bits/stdc++.h>
using namespace std;

int main () {
    int a;
    scanf("%d", &a);
    if(a%2==1){
        printf("%d", (a/2) * (a/2 + 1));
    } else {
        printf("%d", a/2 * a/2);
    }
}