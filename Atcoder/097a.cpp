#include <bits/stdc++.h>
using namespace std;
int main () {
    int a,b,c,d;
    scanf("%d %d %d %d", &a,&b,&c,&d);
    int x=abs(a-b);
    int y=abs(b-c);
    int z=abs(c-a);
    if ( z <= d || (x <= d && y <= d)) {
        printf("%s","Yes");
    } else {
        printf("%s", "No");
    }
}