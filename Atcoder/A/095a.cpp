#include <bits/stdc++.h>
using namespace std;
int main () {
    int ans = 700;
    char l[3];
    scanf("%s", l);
    for(int i = 0 ; i<3;i++){
        if(l[i] == 'o') {
            ans += 100;
        }
    }
    printf("%d", ans);
}