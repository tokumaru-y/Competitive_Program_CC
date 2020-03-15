#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
int main () {
    int n,w;
    scanf("%d %d",&n,&w);
    long long dp[n+1][100000+10];
    for(int i=0;i<n+1;i++)for(int j=0;j<=100000;j++)dp[i][j] = INF;
    dp[0][0]=0;
    long long ll[n][2]={};
    for(int i=0;i<n;i++){
        long long w,v;
        scanf("%lld %lld",&w,&v);
        ll[i][0]=w;ll[i][1]=v;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=100000;j++){
            if(j-ll[i][1] >=0){
                dp[i][j-ll[i][1]] + ll[i][0] < dp[i+1][j] ? dp[i+1][j] = dp[i][j-ll[i][1]] + ll[i][0]: dp[i+1][j]=dp[i+1][j];
            }
            dp[i+1][j] > dp[i][j] ? dp[i+1][j] = dp[i][j] : dp[i+1][j]=dp[i+1][j];
        }
    }
    long long ans = 0;
    for(int i=0;i<=100000;i++){
        if(dp[n][i] <= w){
            ans = i;
        }
    }
    printf("%lld", ans);
}