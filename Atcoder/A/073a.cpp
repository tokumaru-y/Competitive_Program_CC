#include <bits/stdc++.h>
using namespace std;
int main (){
    char s[2];
    scanf("%s",s);
    bool flag = false;
    for(int i=0;i<2;i++){
        if(s[i] == '9'){
            flag=true;
        }
    }
    if(flag){
        printf("%s","Yes");
    } else {
        printf("%s", "No");
    }
}