#include <bits/stdc++.h>
using namespace std;
int main () {
    char ll[19];
    scanf("%s",ll);
    for(int i=0;i<19;i++){
        if(i==5 || i==13){
            printf(" ");
        }else {
            printf("%c",ll[i]);
        }
    }
}