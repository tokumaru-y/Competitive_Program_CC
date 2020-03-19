#include <bits/stdc++.h>
using namespace std;
int main () {
    char s[3];
    scanf("%s",s);
    if(s[0] != s[1] || s[1] != s[2]){
        printf("Yes");
    } else {
        printf("No");
    }
}