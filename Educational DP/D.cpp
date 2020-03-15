#include <bits/stdc++.h>
using namespace std;
int main () {
    int n,w;
    scanf("%d %d",&n,&w);
    long long dp[n+1][w+1] ={};

    long long ll[n+1][2]={};
    for(int i=0;i<n;i++){
        long long  a,b;
        scanf("%lld %lld",&a,&b);
        ll[i][0]=a;ll[i][1]=b;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=w;j++){
            if(j-ll[i][0]>=0){
                dp[i+1][j] > dp[i][j-ll[i][0]] + ll[i][1] ? dp[i+1][j] = dp[i+1][j] : dp[i+1][j]= dp[i][j-ll[i][0]] + ll[i][1];
            }
            dp[i+1][j] > dp[i][j] ? dp[i+1][j] = dp[i+1][j] : dp[i+1][j] = dp[i][j];
        }
    }

    printf("%lld", dp[n][w]);
}