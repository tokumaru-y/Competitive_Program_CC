#include <bits/stdc++.h>
using namespace std;

int main () {
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a + b >= c && a <= c) {
        printf("%s", "YES");
    } else {
        printf("%s", "NO");
    }
}