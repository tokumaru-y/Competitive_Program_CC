#include <bits/stdc++.h>
using namespace std;
int main () {
    char s[3];
    scanf("%s",s);
    if(s[0] == s[1] || s[0] == s[2] || s[1] == s[2]){
        printf("No");
    } else {
        printf("Yes");
    }
}