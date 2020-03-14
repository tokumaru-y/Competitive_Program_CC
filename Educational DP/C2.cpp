#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    scanf("%d",&n);
    int ll[n][3];
    for(int i=0;i<n;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        ll[i][0]=a;ll[i][1]=b;ll[i][2]=c;
    }
    long long dp[n][3];
    dp[0][0]=ll[0][0];dp[0][1]=ll[0][1];dp[0][2]=ll[0][2];
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            if(j==0){
                if(dp[i-1][1] > dp[i-1][2]){
                    dp[i][j] = ll[i][j] + dp[i-1][1];
                } else {
                    dp[i][j] =  ll[i][j] + dp[i-1][2];
                }
            } else if(j==1) {
                if(dp[i-1][2] > dp[i-1][0]) {
                    dp[i][j] =  ll[i][j] + dp[i-1][2];
                } else {
                    dp[i][j] = ll[i][j] + dp[i-1][0];
                }
            } else {
                if(dp[i-1][0] > dp[i-1][1]){
                    dp[i][j] =  ll[i][j] + dp[i-1][0];
                } else {
                    dp[i][j] = ll[i][j] + dp[i-1][1];
                }
            }
        }
    }
    if (dp[n-1][0] >= dp[n-1][1] && dp[n-1][0] >= dp[n-1][2]){
        printf("%lld", dp[n-1][0]);
    } else if (dp[n-1][1] >= dp[n-1][2] && dp[n-1][1] >= dp[n-1][0]){
        printf("%lld",dp[n-1][1]);
    } else {
        printf("%lld", dp[n-1][2]);
    }
}