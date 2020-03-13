#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[4];
    scanf("%s", s);
    int ans =0;
    for(int i = 0;i<4;i++){
        if(s[i] == '+'){
            ans += 1;
        } else {
            ans -= 1;
        }
    }
    printf("%d", ans);
}