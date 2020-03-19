#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;scanf("%d",&n);
    int cnt =0;
    bool flag=false;
    while (n>0) {
        if(n%2==1){
            n--;
            flag=true;
        } else {
            n-=2;
        }
        cnt++;
    }
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++){
        if(flag){
            printf("%d\n",1);
            flag=false;
        } else {
            printf("%d\n",2);
        }
    }
}