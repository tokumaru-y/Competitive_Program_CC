#include <bits/stdc++.h>
using namespace std;
int main () {
    char s[2];
    scanf("%s",s);
    int ans = 0;
    for(int i=0;i<2;i++){
        ans +=s[i] - '0';
    }
    printf("%d\n",ans);
}