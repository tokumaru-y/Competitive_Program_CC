#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[3];
    for(int i= 0;i<3;i++){
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for(int i=0;i<3;i++){
        int tmp = a[i] * 10;
        for(int j=0;j<3;j++){
            if(i==j) continue;
            tmp += a[j];
        }
        if (ans < tmp){
            ans = tmp;
        }
    }
    printf("%d", ans);
}