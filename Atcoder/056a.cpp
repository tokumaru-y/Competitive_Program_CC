#include <bits/stdc++.h>
using namespace std;
int main () {
    char a,b;
    scanf("%c %c",&a,&b);
    if((a=='H' && b=='H') || (a=='D' && b=='D')){
        printf("H");
    } else {
        printf("D");
    }
}