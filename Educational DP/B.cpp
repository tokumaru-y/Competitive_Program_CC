#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
int main() {
    int n,k;
    scanf("%d %d", &n,&k);
    long long h[n];
    long long dp[n];
    for(int i =0;i<n;i++) dp[i] = INF;
    for(int i=0;i<n;i++) scanf("%lld",&h[i]);
    dp[0] = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;((j<=i+k)&&(j<n));j++){
            (dp[j] > dp[i] + abs(h[j]-h[i])) ? dp[j] = dp[i] + abs(h[j] -h[i]) : dp[j] = dp[j];
        }
    }
    printf("%lld", dp[n-1]);
}