#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
int main () {
    long n;
    scanf("%ld",&n);
    long long h[100010];
    long long dp[100010];
    for(int i=0;i<n;i++) scanf("%lld",&h[i]);
    for(int i=0;i<n;i++) dp[i] = INF;
    dp[0] = 0;
    for(int i=0;i<n;i++){
        (dp[i] > dp[i-1] + abs(h[i] - h[i-1])) ? dp[i] = dp[i-1] + abs(h[i] - h[i-1]) : dp[i] = dp[i];
        if(i>1) (dp[i] > dp[i-2] + abs(h[i] - h[i-2])) ? dp[i] = dp[i-2] + abs(h[i] - h[i-2]): dp[i]=dp[i];
    }
    printf("%lld", dp[n-1]);
}
