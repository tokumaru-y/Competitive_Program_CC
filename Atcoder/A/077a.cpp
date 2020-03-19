#include <bits/stdc++.h>
using namespace std;

int main () {
    char a[3];char b[3];
    scanf("%s", a);scanf("%s", b);
    bool flag = true;
    for(int i = 0 ;i<3;i++){
        if(a[i] != b[2-i]) flag=false;
    }
    if(flag){
        printf("%s", "YES");
    } else {
        printf("%s", "NO");
    }
}