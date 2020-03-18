#include <bits/stdc++.h>
using namespace std;
int main () {
    int a,b,c;
    scanf("%d",&a);scanf("%d",&b);scanf("%d",&c);
    for(int i=c;i<=20000;i++){
        if(i%a==0 && i%b==0){
            printf("%d\n",i);
            break;
        }
    }
}