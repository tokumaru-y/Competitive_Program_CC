#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[3];
    scanf("%s",s);
    int x=0;int y=0;int z=0;
    for(int i=0;i<3;i++){
        if(s[i]=='a'){
            x++;
        } else if(s[i]=='b'){
            y++;
        } else {
            z++;
        }
    }
    if(x==1 && y==1 && z==1){
        printf("%s", "Yes");
    } else {
        printf("%s","No");
    }
}