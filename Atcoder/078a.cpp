#include <bits/stdc++.h>
using namespace std;
int main () {
    char a,b;
    scanf("%c %c", &a,&b);
    if(a < b){
        printf("%c",'<');
    } else if (a > b) {
        printf("%c",'>');
    } else {
        printf("%c",'=');
    }
}