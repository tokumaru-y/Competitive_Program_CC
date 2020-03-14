#include <bits/stdc++.h>
using namespace std;
int main () {
    int a,b,c,d;
    scanf("%d %d %d %d", &a,&b,&c,&d);
    if (a + b < c + d) {
        printf("%s", "Right");
    } else if (a +b == c +d){
        printf("%s", "Balanced");
    } else {
        printf("%s", "Left");
    }
}