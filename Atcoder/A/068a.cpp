#include <bits/stdc++.h>
#include <string>
using namespace std;
int main () {
    char s[3];
    scanf("%s",s);
    string ans = "ABC";
    for(int i=0;i<3;i++){
        ans += s[i];
    }
    printf("%s",ans.c_str());
}