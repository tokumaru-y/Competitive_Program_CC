#include <bits/stdc++.h>
using namespace std;
int main () {
    int a,b;
    scanf("%d %d",&a,&b);
    int ll[13] = {2,3,4,5,6,7,8,9,10,11,12,13,1};
    if(a==b){
        printf("Draw");
    } else{
        for(int i =0;i<13;i++){
            if(ll[i]==a){
                printf("Bob");
                break;
            } else if (ll[i]==b){
                printf("Alice");
                break;
            }
        }
    }
}