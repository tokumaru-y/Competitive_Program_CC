#include <bits/stdc++.h>
using namespace std;

int main () {
    int a[3];
    for(int i=0;i<3;i++){
        scanf("%d", &a[i]);
    }
    int ans = 100000;
    for(int i = 0 ;i<3;i++){
        for(int j = 0;j<3;j++){
            for(int k=0;k<3;k++){
                if(i==j||j==k||k==i) continue;
                int tmp = abs(a[i]-a[j]) + abs(a[j] - a[k]);
                if(tmp<ans){
                    ans = tmp;
                }
            }        
        }
    }
    printf("%d", ans);
}