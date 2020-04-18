#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
using namespace std;

const long long INF = 1LL << 60;
const int MOD = (int)1e9 + 7;
typedef long long ll;
//約数列挙
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    //sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};

signed main () {
    int n,m;scanf("%d %d",&n,&m);
    vector<int> distance(n);vector<int> cost(m);
    REP(i,n){
        int a;scanf("%d",&a);
        distance[i] = a;
    }
    REP(j,m){
        int b;scanf("%d",&b);
        cost[j] = b;
    }
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,INF));
    dp[0][0]=0;
    FOR(i,0,n){
        FOR(j,0,m){
            dp[i][j+1] = min(dp[i][j+1], dp[i][j]);
            dp[i+1][j+1]= min(dp[i+1][j+1], dp[i][j]+cost[j]*distance[i]);
        }
        //REP(k,n+1)printf("%lld ",dp[i][k]);
        //printf("\n");
    }
    
    ll ans = INF;
    FOR(i,1,m+1)ans = min(dp[n][i],ans);
    printf("%lld\n",ans);
}