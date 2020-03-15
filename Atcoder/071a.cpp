#include <bits/stdc++.h>
using namespace std;
int main () {
    int x,a,b;
    scanf("%d %d %d", &x,&a,&b);
    int k = abs(x-a);int t = abs(x-b);
    if(k < t){
        printf("%c",'A');
    } else {
        printf("%c",'B');
    }
}