#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[3];
    scanf("%s", s);
    for(int i=0; i<3; i++){
        if(s[i] == '1'){
            printf("%d", 9);
        } else {
            printf("%d", 1);
        }
    }
}