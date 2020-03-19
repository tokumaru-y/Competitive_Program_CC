#include <bits/stdc++.h>
using namespace std;
int main () {
    char s[3];
    scanf("%s", s);
    int ans =0;
    for(int i = 0;i<3;i++){
        if (s[i] == '1') ans++;
    }
    printf("%d", ans);
}